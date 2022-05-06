#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace Chrono {

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator+(const Month& m, int n)
{
    int r = int(m) + n;
    r %= int(Month::dec);

    if (r == 0) return Month::dec;  // Revert effect of modulo
    return Month(r);
}

// Define other operators based on +
Month operator-(const Month& m, int n) { return (m+(-n)); }
Month& operator+=(Month& m, int n) { m = m + n; return m; }

bool operator<(const Month& m, int n) { return int(m) < n; }
bool operator>(const Month& m, int n) { return int(m) > n; }

class Date {
public:
    class Invalid {};
    Date(int yy, Month mm, int dd);
    void add_day(int n);              // increase the Date by n days
    Month month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
private:
    int y;          // year
    Month m;
    int d;          // day
    bool is_valid();
};

Date::Date(int yy, Month mm, int dd)
        :y{yy}, m{mm}, d{dd}
{
    if (!is_valid()) throw Invalid{};
}

bool Date::is_valid()
// Checks if Date object is valid
{
    if (d < 1 || d > 31) return false;
    if (m < Month::jan || m > Month::dec) return false;
    return true;
}

void Date::add_day(int n)
// add or subtract days from a Date.
{
    // assuming every month has 31 days
    int n_d = n % 31;          // days out of months, to increase
    int n_m = (n / 31) % 12;   // months out of years, to increase
    int n_y = n / (31*12);     // years to increase

    d += n_d;
    // Day check
    if (d > 31) { ++n_m; d -= 31; }     // Day overflow
    if (d < 1)  { --n_m; d += 31; }     // Day underflow
 
    // check year
    if (Month::dec < (int(m)+n_m)) ++n_y;
    if (Month::jan > (int(m)+n_m)) --n_y;
    m += n_m;   // m is of Month type
    y += n_y;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}

};

int main()
try
{
    using Chrono::Date;
    using Chrono::Month;

    Date today{1978, Month::jun, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    // add_day() check
    Date test{2010, Month::dec, 31};

    test.add_day(6);   // should be 2011 January 6th
    cout << "January the 6th 2011? " << test << '\n';
    test.add_day(-6);  // should be 2010 December 31st again
    cout << "December the 31st 2010? " << test << '\n';

    test = Date{2010, Month::feb, 5};
    test.add_day(-7);   // should be 2010 January 29th 
    cout << "January the 29th 2010? " << test << '\n';
    
    test.add_day(7);    // should be 2010 February 5th again 
    cout << "February the 5th 2010? " << test << '\n';
    
    test.add_day(3650);  // should be a year after ...
    cout << "February 2020? " << test << '\n';
    
    test.add_day(-3650); // should be a year before ...
    cout << "February 2010? " << test << '\n';

    // Invalid date
    Date today_e{2004, Month::dec, -5};

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(Chrono::Date::Invalid)
{
    cerr << "Invalid date!\n";
    return 2;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 3;
}
