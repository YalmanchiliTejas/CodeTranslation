#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 4e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//
struct p {
    ll a, b, v;
    p(ll a = 0, ll b = 0, ll v = 0) : a(a), b(b), v(v) {}
};

ll dp[2000][2000];

int main() {
    init();
    ll N;
    cin >> N;
    vl A(N * 3), C(N);
    rep(i, N * 3) cin >> A[i], A[i]--;

    auto check = [&](ll a1, ll a2) -> bool{
        if (a1 == a2) {
            return C[a1] >= 2;
        } else {
            return (C[a1] >= 1 and C[a2] >= 1);
        }
    };

    C[A[0]]++, C[A[1]]++;
    vl R(3), M(N);      // M[i] : iを残り２つに残したときの最大値
    ll d = 0, maxv = 0; // 3個とも同じ数字だったときの増分, 現在の最大値
    queue<p> q, maxq;   // 2つのindex, 更新後のvalueを持つ

    rep(i, N - 1) {
        rep(j, 3) R[j] = A[i * 3 + j + 2];
        sort(all(R));

        // 3つとも等しい
        if (R[0] == R[1] and R[1] == R[2]) {
            d++;
        }
        // 2つ等しい
        else if (R[0] == R[1] or R[1] == R[2]) {
            // a: 2つある要素, b: 1つの要素
            ll a = (R[0] == R[1] ? R[0] : R[2]), b = (R[0] == R[1] ? R[2] : R[0]);
            
            rep(n, N) if (check(a, n)) q.emplace(n, b, dp[a][n] + 1);
            if (check(b, b)) q.emplace(a, a, dp[b][b] + 1);

            maxq.emplace(a, a, maxv), maxq.emplace(a, b, maxv);
            rep(n, N) maxq.emplace(n, a, M[n]), maxq.emplace(n, b, M[n]);
        }
        // それぞれ異なる
        else {
            ll a = R[0], b = R[1], c = R[2];
            if (check(a, a)) q.emplace(b, c, dp[a][a] + 1);
            if (check(b, b)) q.emplace(a, c, dp[b][b] + 1);
            if (check(c, c)) q.emplace(a, b, dp[c][c] + 1);

            maxq.emplace(a, b, maxv), maxq.emplace(b, c, maxv), maxq.emplace(c, a, maxv);
            rep(n, N) maxq.emplace(n, a, M[n]), maxq.emplace(n, b, M[n]), maxq.emplace(n, c, M[n]);
        }

        // dp配列を更新
        while (!maxq.empty()) {
            auto [i1, i2, v] = maxq.front();
            maxq.pop();

            chmax(dp[i1][i2], v), chmax(dp[i2][i1], v);
            chmax(M[i1], v), chmax(M[i2], v);
        }
        while (!q.empty()) {
            auto [i1, i2, v] = q.front();
            q.pop();
            if (dp[i1][i2] >= v) continue;

            dp[i1][i2] = dp[i2][i1] = v;
            chmax(M[i1], v), chmax(M[i2], v);
            chmax(maxv, v);
        }

        rep(j, 3) C[R[j]]++;
    }

    // 最後の残り1要素を考える
    ll endv = A.back();
    if (check(endv, endv)) dp[endv][endv]++;

    ll ans = 0;
    rep(i, N) rep(j, N) chmax(ans, dp[i][j] + d);
    cout << ans << endl;
}