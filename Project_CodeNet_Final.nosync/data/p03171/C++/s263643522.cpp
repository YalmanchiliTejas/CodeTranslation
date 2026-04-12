#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
    int N;
    cin >> N;

    vll a(N);
    for (auto &&e: a) cin >> e;

    vector<vll> dp(N + 1, vll(N + 1, 0));

    FOR(size, 1, N + 1) {
        REP(i, N) {
            int j = i + size;
            if (j > N) continue;

            if ((N - size) % 2 == 0) {
                dp[i][j] = max(
                        a[i] + dp[i + 1][j],
                        dp[i][j - 1] + a[j - 1]
                );
            } else {
                dp[i][j] = min(
                        -a[i] + dp[i + 1][j],
                        dp[i][j - 1] - a[j - 1]
                );
            }
        }
    }

    return dp[0][N];
}


int main() {
    cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);

//    cout << (solve() ? "First" : "Second") << endl;
//    cout << (solve() ? "YES" : "NO") << endl;
    cout << solve() << endl;
//    solve();

    return 0;
}
