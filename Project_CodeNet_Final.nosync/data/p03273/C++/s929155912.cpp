#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
const int MAXN=101,MAXM=101;
int n,m;
bool bo,b[MAXN][MAXM];
string s[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		if(s[i][j]!='.')
			bo=true;
		if(!bo)
			for(int j=0;j<m;++j)
			b[i][j]=true;
		bo=false;
	}
	for(int j=0;j<m;++j)
	{
		for(int i=1;i<=n;++i)
		if(s[i][j]!='.')
			bo=true;
		if(!bo)
			for(int i=1;i<=n;++i)
			b[i][j]=true;
		bo=false;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		if(!b[i][j])
			cout<<s[i][j],bo=true;
		if(bo) printf("\n");
		bo=false;
	}
}