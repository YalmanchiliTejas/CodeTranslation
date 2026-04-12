#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define for1(a,b,i) for(int i=a;i<=b;++i)
#define FOR2(a,b,i) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
inline int read() {
	int f=1,sum=0;
	char x=getchar();
	for(;(x<'0'||x>'9');x=getchar()) if(x=='-') f=-1;
	for(;x>='0'&&x<='9';x=getchar()) sum=sum*10+x-'0';
	return f*sum;
}

#define M 105
#define mod 1000000007
int n;
int a[M];
int tot,st[M],dui[M],f[M][M];

inline int qpow(int x,int ci) {
	int sum=1;
	for(;ci;ci>>=1,x=1ll*x*x%mod)
		if(ci&1) sum=1ll*x*sum%mod;
	return sum;
}

inline void inc(int &x,int y){x+=y,x-=x>=mod?mod:0;}

int main() {
	//freopen("a.in","r",stdin);
	n=read();
	for1(1,n,i) {
		a[i]=read();
		dui[i]=a[i]-1;
	}
	sort(dui+1,dui+n+1);
	for1(1,n,i) {
		if(dui[i]!=dui[i-1]) ++tot;
		st[tot]=dui[i];
	}
	for1(1,n,i) {
		if(a[i]==1) a[i]=0;
		else for1(1,tot,j) if(a[i]==st[j]+1) a[i]=j;
	}
	f[1][0]=2;
	for1(1,a[1],i) f[1][i]=1ll*(qpow(2,st[i]-st[i-1])-1)*qpow(2,st[a[1]]-st[i]+1)%mod;
	//for1(0,a[1],i) cout<<f[1][i]<<" "; cout<<endl;
	for1(2,n,i) {
		for1(1,tot,j) {
			if(!f[i-1][j]) continue;
			if(j<=a[i]) {
				int k=1;
				if(a[i]>a[i-1]) k=qpow(2,st[a[i]]-st[a[i-1]]);
				inc(f[i][j],1ll*k*f[i-1][j]%mod);
			}
			else {
				inc(f[i][0],2ll*f[i-1][j]%mod);
			}
		}
		inc(f[i][0],2ll*f[i-1][0]%mod);
		if(a[i]>a[i-1]) {
			for1(a[i-1]+1,a[i],j) {
				inc(f[i][j],1ll*f[i-1][0]*(qpow(2,st[j]-st[j-1])-1)%mod*qpow(2,st[a[i]]-st[j]+1)%mod);
			}
		}
	}
	//for1(0,a[n],i) cout<<f[n][i]<<" "; cout<<endl;
	int ans=0;
	for1(0,tot,i) inc(ans,f[n][i]);
	cout<<ans<<endl;
}