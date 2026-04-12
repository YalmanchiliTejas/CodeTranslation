#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	if (str.find("A")!=string::npos)
	{
		if (str.find("B")==string::npos)
		{
			cout<<"No";
		}
		else cout<<"Yes";
	}
	else if (str.find("B")!=string::npos)
	{
		if (str.find("A")==string::npos)
		{
			cout<<"No";
		}
		else cout<<"Yes";
	}
	cout<<endl;
	return 0;
}
