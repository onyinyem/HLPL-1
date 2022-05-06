#include "std_lib_facilities.h"

struct Date {
    int y, m, d;                    // year, month, day
    Date(int yy, int mm, int dd);   // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
};

Date::Date(int yy, int mm, int dd)
{
    if (dd < 1 || dd > 31) error("Invalid day");
    if (mm < 1 || mm > 12) error("Invalid month");

    y = yy;       
    m = mm;
    d = dd;
}

void Date::add_day(int n)
// add or subtract days from a Date.
{
    d += n;
     
    if (d > 31) { ++m; d -= 31; }     
    if (d < 1)  { --m; d += 31; }    
    // check Month
    if (m > 12) { ++y; m -= 12; }   
    if (m < 1)  { --y; m += 12; }    
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

int main()
try
{
    Date today{1978, 6, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    // Date test
    Date test{2010, 12, 31};

    test.add_day(6);   // should print 2011 January 6th
    cout << "January the 6th 2011? " << test << '\n';
    test.add_day(-6);  // should print 2010 December 31st again
    cout << "December the 31st 2010? " << test << '\n';

    test = Date{2010, 2, 5};
    test.add_day(-7);   // should print 2010 January 29th 
    cout << "January the 29th 2010? " << test << '\n';
    test.add_day(7);    // should print 2010 February 5th again 
    cout << "February the 5th 2010? " << test << '\n';

    // should print Invalid date
    Date today_e{2004, 13, -5};

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}
