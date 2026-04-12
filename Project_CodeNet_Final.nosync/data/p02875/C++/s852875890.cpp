#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mod 998244353
#define mad(a,b) a=(a+b)%mod
#define N 10000010
ll fac[N],ivf[N],inv[N];
ll C(ll n,ll k){
    if(n<k)return 0;
    if(k<0)return 0;
    return fac[n]*ivf[k]%mod*ivf[n-k]%mod;
}

ll po(ll x,ll y){
    ll res=1;
    for(;y;y>>=1){
	if(y&1)res=res*x%mod;
	x=x*x%mod;
    }
    return res;
}
ll rui[N];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    fac[0]=ivf[0]=inv[1]=1;
    for(ll i=1;i<N;i++){
	if(i>1)inv[i]=(mod-(mod/i*inv[mod%i]%mod))%mod;
	fac[i]=fac[i-1]*i%mod;
	ivf[i]=ivf[i-1]*inv[i]%mod;
    }
    ll n; cin>>n;
    ll ans=po(3,n);
    for(ll x=n/2+1;x<=n;x++){
	mad(ans,-2*C(n,x)*po(2,n-x)%mod);
    }
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
}

