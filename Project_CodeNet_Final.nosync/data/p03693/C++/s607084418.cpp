#include<iostream>
using namespace std;
#include<string>
#include<strstream>
#include<sstream>

int main()
{
	char a, b, c;
	cin >> a >> b >> c;
	string s  ;
	s += a ;
	s += b;
	s += c;	stringstream ss(s);
	int x=0;
	ss >> x;
	
	if ((x & 3)==0)
		cout << "YES";
	else
		
	cout << "NO";

}
