#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

int dfs(int i, int k, string &S) {
    if (i + K - k > S.size())
        return 0;
    if (k == K)
        return 1;
    int res = 0;
    int now = S[i] - '0';
    if (now == 0) {
        res += dfs(i + 1, k, S);
    } else {
        res += dfs(i + 1, k + 1, S);
        int n = S.size() - 1 - i;
        //0
        if (n >= K - k) {
            int tmp = 1;
            REP(i, K - k) {
                tmp *= 9 * (n - i);
                tmp /= (i + 1);
            }
            res += tmp;
        }
        //0以外
        if (n >= K - k - 1) {
            int tmp = 1;
            REP(i, K - k - 1) {
                tmp *= 9 * (n - i);
                tmp /= (i + 1);
            }
            res += (now - 1) * tmp;
        }
    }
    return res;
}

signed main() {
    cin >> S >> K;
    cout << dfs(0, 0, S) << endl;
}