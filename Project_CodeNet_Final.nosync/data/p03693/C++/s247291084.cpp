#include<iostream>
//#include<CastingInterop.h>
#include<string>
#include<array>
using namespace std;

int main()
{
	int a, b, c , x=0 ;
	cin >> a >> b >> c;
	x = (a * 100) + (b * 10) + c;
	
	if (x % 4 == 0)
		cout << "YES";
	else
		cout << "NO";}