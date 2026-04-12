#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
namespace mydef {
const int INF = 1ll << 60;
const int MOD = 1e9 + 7;
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
bool dbg = false;
}  // namespace mydef
using namespace mydef;
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int, int>>
#define vvp vector<vector<pair<int, int>>>
#define pi pair<int, int>
//#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define asn ans

int N, A[101010];
int memo[2020][2020];

void solve() {
    //vector<vi> memo(N, vi(N, -INF));
    Fill(memo, -INF);
    vi MAX(N, -INF);
    memo[A[0]][A[1]] = 0;
    memo[A[1]][A[0]] = 0;
    chmax(MAX[A[0]], 0ll);
    chmax(MAX[A[1]], 0ll);
    int SUM_ALL = 0;
    int ans = 0;
    for (int k = 0; k < N; k++) {
        vector<pair<pair<int, int>, int>> update;
        update.reserve(N * 10);
        if (k != N - 1) {
            int x = k * 3 + 2;  //A[x],A[x+1],A[x+2]
            if (A[x] == A[x + 1] && A[x + 1] == A[x + 2]) {
                SUM_ALL++;
                continue;
            }
            int MAX_ALL = 0;
            for (int i = 0; i < N; i++) {
                chmax(MAX_ALL, MAX[i]);
            }
            update.emplace_back(make_pair(A[x], A[x + 1]), MAX_ALL);
            update.emplace_back(make_pair(A[x], A[x + 2]), MAX_ALL);
            update.emplace_back(make_pair(A[x + 1], A[x + 2]), MAX_ALL);
            for (int i = 0; i < N; i++) {
                update.emplace_back(make_pair(A[x], i), MAX[i]);
                update.emplace_back(make_pair(A[x + 1], i), MAX[i]);
                update.emplace_back(make_pair(A[x + 2], i), MAX[i]);
            }
            for (int i = 0; i < 3; i++) {
                update.emplace_back(make_pair(A[x + ((i + 1) % 3)], A[x + ((i + 2) % 3)]), memo[A[x + i]][A[x + i]] + 1);
                if (A[x + ((i + 1) % 3)] == A[x + ((i + 2) % 3)]) {
                    int a = A[x + ((i + 1) % 3)];
                    for (int j = 0; j < N; j++) {
                        update.emplace_back(make_pair(j, A[x + i]), memo[a][j] + 1);
                    }
                }
            }
            for (auto& p : update) {
                int a = p.first.first, b = p.first.second, scr = p.second;
                chmax(memo[a][b], scr);
                chmax(memo[b][a], scr);
                chmax(MAX[a], scr);
                chmax(MAX[b], scr);
            }
        } else {
            int x = k * 3 + 2;  //A[x]
            for (int i = 0; i < N; i++) {
                chmax(ans, MAX[i]);
            }
            chmax(ans, memo[A[x]][A[x]] + 1);
        }
    }
    cout << ans + SUM_ALL << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N * 3; i++) {
        cin >> A[i];
        A[i]--;
    }

    solve();
    return 0;
}
