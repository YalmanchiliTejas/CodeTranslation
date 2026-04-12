#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,x,m,a[N],k[N],b,c,s,ans;
int main(){
    fast_io;
    cin >> n >> x >> m;
    a[1]=x;
    k[x]=1;
    for(ll i=2; i<N; i++){
        a[i]=a[i-1]*a[i-1]%m;
        if(k[a[i]]){
            b=k[a[i]];
            c=i-b;
            break;
        }
        k[a[i]]=i;
    }
    for(ll i=0; i<c; i++){
        s+=a[i+b];
    }
    for(ll i=1; i<b; i++) ans+=a[i];
    n-=b-1;
    ans+=(n/c)*s;
    n%=c;
    for(ll i=0; i<n; i++) ans+=a[b+i];
    cout << ans << '\n';
    return 0;
}
