#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// global array
vector<int> gv ={1,2,4,8,16,32,64,128,256,512};

void f(vector <int> v)
{
	// define local vector 1
	vector <int> lv;
	
  //copying values
	for (int i = 0;i < v.size();i++)
		lv.push_back(gv[i]);
	
  //printing values
	cout << "Local vector 1: ";
	for (int i = 0;i < lv.size();i++)
		cout<<lv[i]<<" ";
	
  // printing
	cout << endl;
	
  // define local vector 2
	vector <int> lv2;
	
  //copying values
	for (int i = 0;i < v.size();i++)
		lv2.push_back( v[i]);
	
  //printing values
	cout << "Local vector 2: ";
	for (int i = 0;i < lv2.size();i++)
		cout << lv2[i] << " ";
	cout << endl;
}

int main()
{
	f(gv);
	vector <int> vv = {1,2,6,24,120,720,5040,40320,362880,3628800};
	f(vv);

	return 0;
}
