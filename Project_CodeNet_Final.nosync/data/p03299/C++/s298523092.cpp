#include<iostream>
#include<cstdio>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=220,P=1e9+7;
int n,m,ans,a[N],b[N],f[N][N];
void chk(int&x){x-=P;x+=(x>>31)&P;}
int qpw(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%P)if(y&1) z=1ll*z*x%P;return z;}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);a[0]=1;b[n+1]=1;
	FOR(i,1,n) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+2);m=unique(b+1,b+n+2)-b;
	FOR(i,0,n) a[i]=lower_bound(b+1,b+m,a[i])-b;
	f[0][1]=1;
	FOR(i,1,n)FOR(j,1,a[i-1])if(f[i-1][j]){
		int x=a[i-1],y=a[i];
		if(x>y){
			chk(f[i][min(j,y)]+=f[i-1][j]);
			if(j>=y) chk(f[i][y]+=f[i-1][j]);
		}
		else{
			if(j<x) chk(f[i][j]+=1ll*qpw(2,b[y]-b[x])*f[i-1][j]%P);
			else FOR(k,x,y)
			chk(f[i][k]+=2ll*(qpw(2,b[y]-b[k])-(k==y?0:qpw(2,b[y]-b[k+1]))+P)%P*f[i-1][j]%P);
		}
	}
	FOR(j,1,m) chk(ans+=f[n][j]);
	cout<<ans<<'\n'; 
}