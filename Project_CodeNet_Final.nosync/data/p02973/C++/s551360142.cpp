#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> v(n+1, INF), a(n);
    rep(i,n) cin >> a[i];
    for(int i = n-1; i >= 0; --i){
        auto idx = lower_bound(v.begin(), v.end(), a[i]+1);
        *idx = a[i];
    }
    ll ans = 0;
    rep(i,n){
        if(v[i] < INF) ++ans;
    }
    cout << ans << endl;
    return 0;
}
