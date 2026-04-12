#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
int a[N],b[N],h[N],f[N][N];
inline int qpow(int y,int x=2){int A=1;for(;y;y>>=1,x=(ll)x*x%mod)if(y&1)A=(ll)A*x%mod;return A;}
int main()
{	int n,ans=0; cin>>n;
	for(rint i=1;i<=n;i++) scanf("%d",&h[i]),b[i]=h[i];
	sort(b+1,b+n+1); int l=unique(b+1,b+n+1)-b-1;
	for(rint i=1;i<=n;i++) a[i]=lower_bound(b+1,b+l+1,h[i])-b;
	f[0][0]=1;
	for(rint i=1;i<=n;i++)
	{	f[i][0]=f[i-1][0]*2%mod; 
		for(rint j=a[i]+1;j<=a[i-1];j++) (f[i][0]+=2*f[i-1][j]%mod)%=mod;
		for(rint j=1;j<=a[i];j++)
		{	f[i][j]=(ll)f[i-1][j]*qpow(max(0,b[a[i]]-b[a[i-1]]))%mod;
			if(j>a[i-1])
			(f[i][j]+=((j!=1)+1LL)*f[i-1][0]%mod*qpow(b[a[i]]-b[j])%mod*(qpow(b[j]-b[j-1])-1-(j==1))%mod)%=mod;
		}
	}
	for(rint i=0;i<=a[n];i++) (ans+=f[n][i])%=mod;
	cout<<ans;
	return 0;
}
