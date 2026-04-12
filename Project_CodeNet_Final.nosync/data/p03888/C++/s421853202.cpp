#include<iostream>
#include<iomanip>
using namespace std;

long double a,b;

int main()
{
	 cin>>a>>b;
	 cout<<fixed<<setprecision(6)<<a*b/(a+b);
	return 0;
}