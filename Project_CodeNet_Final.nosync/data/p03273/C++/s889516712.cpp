#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char s[101][101];bool c[101],l[101];int cv[101],lv[101];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')++cv[i],++lv[j];
	for(int i=1;i<=n;i++)
		if(cv[i]==m)c[i]=1;
	for(int j=1;j<=m;j++)
		if(lv[j]==n)l[j]=1;
	for(int i=1;i<=n;i++)
	{
		if(c[i])continue;
		for(int j=1;j<=m;j++)
			if(!l[j])cout<<s[i][j];
		cout<<endl;
	}
	return 0;
} 