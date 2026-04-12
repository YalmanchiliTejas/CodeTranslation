#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n;cin>>n;
    vector<ll> h(n);
    rep(i,n) cin>>h[i];

    ll ans=0;
    rep(i,n){
        bool can=true;
        for(ll j=0;j<i;j++){
            if(h[i]<h[j]) can=false;
        }
        if(can==true){
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}