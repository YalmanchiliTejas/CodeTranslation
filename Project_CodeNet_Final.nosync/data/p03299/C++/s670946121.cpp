#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
using namespace std;
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
const int N=105;
int a[N],mn[N][N];
int fxor[N][N];
int pre[N][N];
int suf[N][N];
int mx[N],g[N],n;
int main(){
	scanf("%d",&n); n++;
	For(i,2,n) scanf("%d",&a[i]);
	a[0]=a[1]=a[n+1]=a[n+2]=1;
	For(i,0,n+2) mn[i][i]=i;
	For(l,0,n+2) For(r,l+1,n+2)
		mn[l][r]=(a[r]<a[mn[l][r-1]]?r:mn[l][r-1]);
	For(i,1,n+2) fxor[i][i-1]=1;
	Rep(l,n+1,1) For(r,l,n+1){
		int dn=max(a[l-1],a[r+1]),md=mn[l][r];
		if (a[md]>=dn) fxor[l][r]=1ll*power(2,a[md]-dn)*fxor[l][md-1]%mo*fxor[md+1][r]%mo;
	}
	For(l,0,n+2){
		CLR(mx,0); mx[l]=a[l];
		For(i,l+1,n+2) mx[i]=min(a[i],mx[i-1]);
		int tmp=pre[l][l]=1,las=l;
		For(r,l+1,n+2){
			pre[l][r]=1ll*tmp*fxor[las+1][r-1]%mo;
			if (mx[r]>=a[r]) tmp=1ll*tmp*fxor[las+1][r-1]%mo,las=r;
		}
	}
	For(r,0,n+2){
		CLR(mx,0); mx[r]=a[r];
		Rep(i,r-1,0) mx[i]=min(a[i],mx[i+1]);
		int tmp=suf[r][r]=1,las=r;
		Rep(l,r-1,0){
			suf[l][r]=1ll*tmp*fxor[l+1][las-1]%mo;
			if (mx[l]>=a[l]) tmp=1ll*tmp*fxor[l+1][las-1]%mo,las=l;
		}
	}
	g[1]=1;
	For(i,2,n+2) For(j,1,i-1){
		int md=mn[j-1][i];
		UPD(g[i],1ll*g[j]*pre[j-1][md]%mo*suf[md][i]%mo);
	}
	printf("%d\n",1ll*g[n+2]*500000004ll%mo);
}