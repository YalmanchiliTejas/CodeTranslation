#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N;
    cin >> N;
    pll p[N];
    ll M[N+1], m[N+1];
    M[0] = 0, m[0] = INF;
    rep(i, N){
        cin >> p[i].first >> p[i].second;
        if(p[i].second < p[i].first) swap(p[i].first, p[i].second);
    }
    sort(p, p+N);
    rep(i, N){
        M[i+1] = max(M[i], p[i].second);
        m[i+1] = min(m[i], p[i].second);
        //cout << M[i+1] << ' ' << m[i+1] << endl;
    }
    ll ans = (p[N-1].first-p[0].first)*(M[N]-m[N]);
    //要素の最大と最小の差
    ll x = M[N]-p[0].first;
    rep(i, N-1){
        ll t = max(M[i+1], p[N-1].first);
        ll s = min(p[i+1].first, m[i+1]);
        ans = min(ans, (t-s)*x);
    }
    cout << ans << endl;
}