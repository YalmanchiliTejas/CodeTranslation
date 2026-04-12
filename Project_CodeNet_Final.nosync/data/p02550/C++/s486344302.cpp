#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(998244353)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> a, ok_a(m+1, false);
    ll bf = x;
    a.push_back(x);
    ok_a[x] = true;
    while(true){
        bf = (bf*bf) % m;
        if(ok_a[bf])break;
        else a.push_back(bf);
        ok_a[bf] = true;
    }
    vector<ll> b, ok_b(m+1, false);
    b.push_back(bf);
    ok_b[bf] = true;
    while(true){
        bf = (bf*bf) % m;
        if(ok_b[bf])break;
        else b.push_back(bf);
        ok_b[bf] = true;
    }
    if(n <= a.size()){
        ll ans = 0;
        rep(i, n)ans += a[i];
        cout << ans << endl;
    }else{
        n -= a.size();
        ll ans = accumulate(all(a), 0LL);
        ll s = b.size();
        ans += (n/s) * accumulate(all(b), 0LL);
        rep(i, n%s)ans += b[i];
        cout << ans << endl;
    }
}
