#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	size_t f1,f2;
	f1=s.find("AB");
	f2=s.find("BA");
	if(f1==string::npos and f2==string::npos)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}