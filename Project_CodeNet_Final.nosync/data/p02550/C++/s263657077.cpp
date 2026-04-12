#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ll N, X, M;
    cin >> N >> X >> M;
    int id[M];
    fill(id, id+M, -1);
    int n, s;
    vector<ll> res;
    for(int i = 0; ; i++){
        if(id[X] != -1){
            n = i-id[X], s = id[X];
            break;
        }
        res.pb(X), id[X] = i;
        X *= X, X %= M;
    }
    ll ans = 0;
    if(N < s){
        rep(i, N) ans += res[i];
        cout << ans << endl; return 0;
    }
    N -= s;
    rep(i, s) ans += res[i];
    ll loop = 0;
    rep2(i, s, s+n-1) loop += res[i];
    ans += loop*(N/n);
    N %= n;
    rep(i, N){
        ans += X;
        X *= X, X %= M;
    }
    cout << ans << endl;
}