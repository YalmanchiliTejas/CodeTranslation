#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	cin>>s;
	for(int i=0;i<s.size()-1;i++) if(s.substr(i,2)=="AC") {cout<<"Yes";exit(0);}
	cout<<"No";
	return 0;
}