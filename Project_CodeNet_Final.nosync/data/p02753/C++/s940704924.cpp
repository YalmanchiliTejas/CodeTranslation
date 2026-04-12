#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	string a;
	cin >> a;
	if(a[0] == a[1] && a[0] == a[2] && a[1] == a[2])
	{
		cout << "No";	
	}	
	else
	{
		cout << "Yes";
	}
}

