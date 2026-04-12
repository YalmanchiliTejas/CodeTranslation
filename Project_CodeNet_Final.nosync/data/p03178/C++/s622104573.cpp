#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (int var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<int>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;

#define all(c) begin(c),end(c)

#define D(x) do { std::cerr << x << " "; } while (0)
#define D2(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)


template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}


template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}


auto solve() {
    string K;
    cin >> K;
    int D;
    cin >> D;

    int N = K.size();

    vector<vvll> dp(N + 1, vvll(D, vll(2, 0)));
    dp[0][0][1] = 1;

    const int MOD = 1e9 + 7;

    REP(i, N) {
        int d = K[i] - '0';

        REP(t, D) {
            // from max
            REP(td, d) {
                dp[i + 1][(t + td) % D][0] += dp[i][t][1];
                dp[i + 1][(t + td) % D][0] %= MOD;
            }
            dp[i + 1][(t + d) % D][1] += dp[i][t][1];
            dp[i + 1][(t + d) % D][1] %= MOD;

            // from not max
            REP(td, 10) {
                dp[i + 1][(t + td) % D][0] += dp[i][t][0];
                dp[i + 1][(t + td) % D][0] %= MOD;
            }
        }
    }

    ll res = (dp[N][0][0] + dp[N][0][1] - 1 + MOD) % MOD;
    return res;
}


int main() {
    cout.precision(30);
    cin.tie(0);
    ios::sync_with_stdio(false);

//    cout << (solve() ? "Heisei" : "TBD") << endl;
//    cout << (solve() ? "YES" : "NO") << endl;
    cout << solve() << endl;
//    solve();

    return 0;
}