#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	string s;
	int n,k;
	cin>>n>>s>>k;
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[k-1])cout<<s[i];
		else cout<<"*";
	}
}