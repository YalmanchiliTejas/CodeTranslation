#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	char s[20];
	cin>>n>>s>>k;
	char ch=s[k-1];
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i] != ch) cout<<'*';
		else cout<<s[i];
	}
	return 0;
 } 