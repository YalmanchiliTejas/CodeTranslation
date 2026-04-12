#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;

const int mo=1000000007;
int power(int x,ll y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
const int N=105;
int a[N],mn[N][N];
int fxor[N][N];
int trans[N][N];
int mx[N],g[N],n;
int main(){
	scanf("%d",&n); n++;
	for (int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[1]=a[n+1]=a[n+2]=1;
	for (int i=1;i<=n;i++){
		mn[i][i]=i;
		for (int j=i+1;j<=n;j++)
			mn[i][j]=(a[j]<a[mn[i][j-1]]?j:mn[i][j-1]);
	}
	for (int i=1;i<=n+2;i++)
		fxor[i][i-1]=1;
	for (int l=n+2;l>=1;l--)
		for (int r=l;r<=n+2;r++){
			if (a[l]<a[l-1]||a[r]<a[r+1]) continue;
			int dn=max(a[l-1],a[r+1]),md=mn[l][r];
			if (a[md]<dn) continue;
			fxor[l][r]=1ll*power(2,a[md]-dn)*fxor[l][md-1]%mo*fxor[md+1][r]%mo;
		}
	for (int l=n+1;l>=1;l--)
		for (int r=l;r<=n+1;r++){
			for (int k=l-1;k<=r+1;k++) mx[k]=0;
			int tmp=a[l-1];
			for (int k=l;k<=r;k++)
				mx[k]=tmp=min(tmp,a[k]);
			tmp=a[r+1];
			for (int k=r;k>=l;k--)
				mx[k]=max(mx[k],tmp=min(tmp,a[k]));
			int las=l-1; trans[l][r]=1;
			for (int k=l;k<=r+1;k++)
				if (mx[k]>=a[k]||k==r+1) trans[l][r]=1ll*trans[l][r]*fxor[las+1][k-1]%mo,las=k;
		}
	g[1]=1;
	for (int i=2;i<=n+2;i++)
		for (int j=1;j<i;j++)
			UPD(g[i],1ll*g[j]*trans[j][i-1]%mo);
	printf("%d\n",1ll*g[n+2]*500000004ll%mo);
}