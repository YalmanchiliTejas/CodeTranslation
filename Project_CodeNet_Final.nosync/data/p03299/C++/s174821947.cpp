//ΔAGC026D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111;
const int MO = 1e9+7;
const int inf = 2e9;
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
int n,h[N],f[N][N],g[N][N];
void solve(int w,int l,int r){
	int i,j,x=inf,y=0;
	for(i=l;i<=r;i=i+1)
		x=min(x,h[i]),y=max(y,h[i]);
	if(x==y){
		f[l][r]=fpow(2,x-w-1);
		g[l][r]=(fpow(2,r-l+1)-2+f[l][r]*2%MO)%MO;
		return;
	}
	f[l][r]=1;
	g[l][r]=1;
	for(i=l;i<=r;i=i+1){
		if(h[i]==x){
			g[l][r]=mul(g[l][r],2);
			continue;
		}
		for(j=i;j<=r&&h[j+1]>x;j=j+1);
		solve(x,i,j);
		f[l][r]=mul(f[l][r],f[i][j]*2);
		if(i==j)
			g[l][r]=mul(g[l][r],g[i][j]*2);
		else
			g[l][r]=mul(g[l][r],g[i][j]+f[i][j]*2%MO);
		i=j;
	}
	g[l][r]=(g[l][r]-f[l][r]*2%MO+MO)%MO;
	f[l][r]=mul(f[l][r],fpow(2,x-w-1));
	g[l][r]=(g[l][r]+f[l][r]*2%MO)%MO;
	//cout<<l<<' '<<r<<' '<<f[l][r]<<' '<<g[l][r]<<endl;
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>h[i];
	solve(0,1,n);
	cout<<g[1][n];
	return 0;
}