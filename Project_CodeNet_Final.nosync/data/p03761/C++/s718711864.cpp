#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;
int n,a[30],b[30];
string st;
int main()
{
	cin>>n;
	for(int i=1; i<=26; i++)
		b[i]=100;
	for(int i=1; i<=n; i++)
	{
		cin>>st;
		for(int j=1; j<=26; j++)
			a[j]=0;
		for(int j=0; j<st.size(); j++)
			a[st[j]-96]++;
		for(int j=1; j<=26; j++)
			b[j]=min(a[j],b[j]);
	}
	for(int i=1; i<=26; i++)
		if(b[i]!=100)
			for(int j=1; j<=b[i]; j++)
				cout<<char(i+96);
	return 0;
}