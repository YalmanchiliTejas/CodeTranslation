#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL_
void debug_out() {cerr << endl;}
template<typename Head,typename... Tail> void debug_out(Head H,Tail... T){cerr << ' ' << H; debug_out(T...);}
#define debug(...) cerr << 'L' << __LINE__ << " [" << #__VA_ARGS__ << "]:",debug_out(__VA_ARGS__)
#define dump(x) cerr << 'L' << __LINE__ << " " << #x << " = " << (x) << endl;
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N; cin >> N;
    ll X,M; cin >> X >> M;

    ll now = X;
    vector<int> visited(M,0);
    vector<int> route;
    while (!visited[now]) {
        visited[now] = 1;
        route.push_back(now);
        now = now*now%M;
    }

    ll n = X;
    int idx = 0;
    while (n != now) {
        n = n*n%M;
        ++idx;
    }

    ll loop = 0;
    int sz = (int)route.size() - idx;
    vector<ll> bf(idx);
    vector<ll> x(sz);
    for (int i = 0;i < idx;++i) bf[i] = route[i];
    for (int i = idx;i < (int)route.size(); ++i) {
        x[i - idx] = route[i];
        loop += route[i];
    }

    ll ans = 0;
    if (N <= idx) {
        rep(i,N) ans += bf[i];
    } else {
        rep(i,idx) ans += bf[i];
        N -= idx;
        ans += loop * (N/sz);
        rep(i,N%sz) ans += x[i];
    }
    cout << ans << '\n';
    return 0;
}