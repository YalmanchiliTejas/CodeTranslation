#include<bits/stdc++.h>
using namespace std;
char a[10];
int l;
int main()
{
	cin>>a;
	l=strlen(a)-1;
	for(int i=0;i<=l;i++)
		if(a[i]=='A'&&a[i+1]=='C')
		{
			cout<<"Yes";return 0;
		}
	cout<<"No";
	return 0;
}