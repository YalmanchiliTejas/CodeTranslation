#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

//二分累乗法
ll mult(ll n,ll m){//n^m%modを求める
    if(m==1){
        return n%mod;
    }else if(m%2==0){//オーバーフロー防止のためにn^(m/2)*n^(m/2)を考える
        ll t=mult(n,m/2);
        return (t*t)%mod;
    }else{//奇数の時はn^(m-1)*nを考える
        ll t=mult(n,m-1);
        return (t*n)%mod;
    }
}

//nCkの1e9+7における余り
template <class T>
T comb_mod(T n,T k){
    T ans=1;
    T r=min(k,n-k);
    FOR(i,n-r+1,n+1){
        ans*=(i%mod);
        ans%=mod;
    }
    FOR(i,1,r+1){
        ans*=mult(i,mod-2);
        ans%=mod;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    FOR(l,1,n){
      ans+=(((l*(n-l))%mod)*(m*m%mod))%mod;
      ans%=mod;
    }
    FOR(l,1,m){
      ans+=(((l*(m-l))%mod)*(n*n%mod))%mod;
      ans%=mod;
    }
    ans*=comb_mod(n*m-2,k-2);
    ans%=mod;
    cout<<ans<<endl;
}