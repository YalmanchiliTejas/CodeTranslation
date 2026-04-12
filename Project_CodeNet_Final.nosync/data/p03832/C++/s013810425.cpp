#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

ll po(ll x,ll y){
    ll res=1;
    for(;y;y>>=1){
	if(y&1)mul(res,x);
	mul(x,x);
    }
    return res;
}
ll invs(ll x){
    return po(x,mod-2);
}
#define N 100010
ll fac[N],inv[N],ivf[N];
ll P(ll n,ll k){
    return fac[n]*ivf[n-k]%mod;
}
int main(){
    fac[0]=ivf[0]=inv[1]=1;
    for(ll i=1;i<N;i++){
	if(i>1)inv[i]=(mod-(mod/i*inv[mod%i]%mod))%mod;
	fac[i]=fac[i-1]*i%mod;
	ivf[i]=ivf[i-1]*inv[i]%mod;
    }
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    
    ll f[1010][1010];
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=0;
    f[a-1][n]=1;
    for(int i=a;i<=b;i++){
	for(int j=0;j<=n;j++){
	    mad(f[i][j],f[i-1][j]);
	    for(int k=c;k<=d&&j-i*k>=0;k++){
		ll res=f[i-1][j];
		mul(res,P(j,i*k));
        mul(res,invs(fac[k]));
		mul(res,po(invs(fac[i]),k));
		mad(f[i][j-i*k],res);
	    }
	}
    }
    cout<<f[b][0]<<endl;
}


