#include<iostream>
#include<string.h>


using namespace std;

string s;
int main()
{
	cin>>s;
	if(s[0] != s[1] || s[1] != s[2])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
