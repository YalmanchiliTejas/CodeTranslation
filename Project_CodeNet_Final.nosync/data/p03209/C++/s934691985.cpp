#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

ll len[51];
ll p[51];

ll dfs(ll N, ll X) {
    if (N == 0) return 1;
    if (X == 0) return 0;
    if (X == len[N] - 1) return 1 + 2 * p[N - 1];
    if (X == len[N] / 2) return 1 + p[N - 1];
    if (X < len[N] / 2) return dfs(N - 1, X - 1);
    return 1LL + p[N - 1] + dfs(N - 1, X - len[N - 1] - 2);
}

void solve() {
    ll N, X;
    cin >> N >> X;
    X--;
    len[0] = p[0] = 1;
    for (ll i = 1; i < 51; i++) {
        len[i] = len[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    cout << dfs(N, X) << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}