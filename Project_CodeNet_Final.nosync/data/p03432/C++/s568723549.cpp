#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
#define rep(i,x) for(int i=0;i<x;i++)
int n,m;
ll dp[8005][205];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[16005],R[16005];
void make(){
	F[0] = 1;
	rep(i,16004) F[i+1] = F[i]*(i+1)%mod;
	rep(i,16005) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
    return F[a]*R[b]%mod*R[a-b]%mod;
}
ll g[16];
int a[(1<<14)],b[(1<<14)],c[(1<<14)];
void mul(int *a,int *b,int *c,int n){
	if (n<=8){
		memset(g,0,sizeof(g));
		rep(i,n)rep(j,n) g[i+j]+=(ll)a[i]*b[j]%mod;
		rep(i,2*n) c[i]=g[i]%mod;
		return;
	}
	int mid = n/2;
	mul(a,b,c,mid); mul(a+mid,b+mid,c+n,mid);
	int x[mid],y[mid],z[n];
	rep(i,mid){
		x[i]=(a[i]+a[i+mid])%mod; y[i]=(b[i]+b[i+mid])%mod;
	}
	mul(x,y,z,mid);
	rep(i,n) z[i]-=c[i]+c[i+n];
	rep(i,n) c[i+mid]=((c[i+mid]+z[i])%mod+mod)%mod;
}
int main(){
	cin>>n>>m; make();
	dp[0][0] = 1;
	rep(j,m){
		rep(q,(1<<14)) a[q]=b[q]=c[q]=0;
		rep(i,n+1){
			ll x = dp[i][j] * R[i] % mod;
			a[i] = x;
			if(i != 0){
				b[i] = R[i+2];
			}
		}
		mul(a,b,c,(1<<13));
		rep(i,n+1){
			dp[i][j+1] = 1LL*c[i]%mod*F[i+2]%mod;
			dp[i][j+1] += dp[i][j]*(C(i+1,2)+1)%mod;
			dp[i][j+1] %= mod;
		}
	}
	ll ans = 0;
	rep(i,n+1){
		ans += dp[i][m] * C(n,i) % mod;
	}
	cout << ans%mod << endl;
}
