#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N=1e2+5;
int n,m,k,l,r;
int f[N],g[N];
char a[N][N];
int main()
{
	cin>>n>>m;
	rep(i,1,n)cin>>a[i]+1;
	rep(i,1,n)rep(j,1,m)
	{
		if(a[i][j]=='#')f[i]=g[j]=1;
	}
	rep(i,1,n)if(f[i]){rep(j,1,m)
	{
		if(g[j])cout<<a[i][j];

	}cout<<endl;}
}
