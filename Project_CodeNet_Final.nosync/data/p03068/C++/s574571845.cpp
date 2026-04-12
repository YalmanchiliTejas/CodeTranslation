#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,a,b,c;
char s[10000];
int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	scanf("%d",&k);
	for(int i=0;i<n;i++)
	{
		if(s[i]!=s[k-1]) printf("*");
		else cout<<s[i];
	}
}