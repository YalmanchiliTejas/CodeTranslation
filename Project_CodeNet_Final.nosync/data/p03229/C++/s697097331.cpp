#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

////////////////////////////////////////////////////////

int main() {
    ll n; cin >> n;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];

    if(n%2 == 0){
        sort(ALL(a));
        Vl u, d;
        rep(i, 0, n/2) d.push_back(a[i]);
        rep(i, n/2, n) u.push_back(a[i]);
        Vl v;
        rep(i, 0, n/2){
            v.push_back(u[i]);
            v.push_back(d[i]);
        }
        ll ans = 0;
        rep(i, 0, sz(v)-1){
            ans += abs(v[i]-v[i+1]);
        }
        co(ans);
    }else{
        ll ans1 = 0, ans2 = 0;
        sort(ALL(a));
        Vl d, u;
        d.push_back(a[n/2]);
        rep(i, 0, n/2) d.push_back(a[i]);
        rep(i, n/2 + 1, n) u.push_back(a[i]);
        Vl v;
        rep(i, 0, n/2){
            v.push_back(d[i]);
            v.push_back(u[i]);
        }
        v.push_back(d[n/2]);
        rep(i, 0, sz(v)-1){
            ans1 += abs(v[i] - v[i+1]);
        }

        //
        // rep(i, 0, sz(d)) cout << d[i] << " ";
        // coel;
        // rep(i, 0, sz(u)) cout << u[i] << " ";
        // coel;
        // rep(i, 0, sz(v)) cout << v[i] << " ";
        // coel;
        //


        d = {}, u = {};
        rep(i, 0, n/2) d.push_back(a[i]);
        rep(i, n/2+1, n) u.push_back(a[i]);
        u.push_back(a[n/2]);
        v = {};
        rep(i, 0, n/2){
            v.push_back(u[i]);
            v.push_back(d[i]);
        }
        v.push_back(u[n/2]);
        rep(i, 0, sz(v)-1){
            ans2 += abs(v[i] - v[i+1]);
        }

        //
        // rep(i, 0, sz(v)) cout << v[i] << " ";
        // coel;
        //

        co(max(ans1, ans2));
    }

    return 0;
}
 
 
