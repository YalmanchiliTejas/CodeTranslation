#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;
template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    int n;
    cin >> n;

    vector<int> v(3*n);
    for (auto &&i : v) scanf("%d", &i), i--;
    auto dp = make_v(n, n, -1);
    stack<tuple<int, int, int>> Q;
    dp[v[0]][v[1]] = 0;
    int aans = 0, vval = 0;
    vector<int> dpp(n, -1);
    dpp[v[0]] = 0;
    dpp[v[1]] = 0;
    for (int w = 0; w < n - 1; ++w) {
        int a = v[3*w+2], b = v[3*w+3], c = v[3*w+4];
        if(a == b && b == c) aans++;
        else {
            if (a == b) {
                for (int i = 0; i < n; ++i) {
                    if (dp[i][a] >= 0) Q.emplace(c, i, dp[i][a] + 1);
                    if (dp[a][i] >= 0) Q.emplace(c, i, dp[a][i] + 1);
                }
            } else if (a == c) {
                for (int i = 0; i < n; ++i) {
                    if (dp[i][a] >= 0) Q.emplace(b, i, dp[i][a] + 1);
                    if (dp[a][i] >= 0) Q.emplace(b, i, dp[a][i] + 1);
                }
            } else if (b == c) {
                for (int i = 0; i < n; ++i) {
                    if (dp[i][c] >= 0) Q.emplace(a, i, dp[i][c] + 1);
                    if (dp[c][i] >= 0) Q.emplace(a, i, dp[c][i] + 1);
                }
            }
            if (dp[a][a] >= 0) Q.emplace(b, c, dp[a][a] + 1);
            if (dp[b][b] >= 0) Q.emplace(a, c, dp[b][b] + 1);
            if (dp[c][c] >= 0) Q.emplace(a, b, dp[c][c] + 1);
            Q.emplace(a, b, vval);
            Q.emplace(a, c, vval);
            Q.emplace(b, c, vval);
            for (int i = 0; i < n; ++i) {
                if (dpp[i] >= 0) {
                    Q.emplace(a, i, dpp[i]);
                    Q.emplace(b, i, dpp[i]);
                    Q.emplace(c, i, dpp[i]);
                }
            }
            while (!Q.empty()) {
                auto[p, q, r] = Q.top();
                Q.pop();
                chmax(dp[p][q], r);
                chmax(dpp[p], r);
                chmax(dpp[q], r);
                chmax(vval, r);
            }
        }
    }
    cout << max(vval, dp[v.back()][v.back()]+1)+aans << "\n";
    return 0;
}