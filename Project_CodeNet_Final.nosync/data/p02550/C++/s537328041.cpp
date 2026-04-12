//#define _GLIBCXX_DEBUG
//#include "atcoder/all"
//using namespace atcoder;
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
#define bit(n, k) (((n) >> (k)) & 1) /*nのk bit目*/
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
bool dbg = true;
}  // namespace mydef
using namespace mydef;
#define pb push_back
//#define mp make_pair
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

int N, X, M;
int memo[101010], seen[101010], num[101010];
int loop = INF, loop_val;

void solve() {
    int ans = 0;
    int A = X;
    A %= M;
    int c = 0;
    while (N) {
        if (N % loop == 0) {
            int cnt = N / loop;
            N -= loop * cnt;
            ans += cnt * loop_val;
        } else {
            ans += A;
            if (seen[A]) {
                loop = num[A] - c;
                loop_val = memo[A] - ans;
            }
            num[A] = c;
            seen[A] = 1;
            memo[A] = ans;
            A = A * A;
            A %= M;
            N--;
            c++;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> X >> M;

    solve();
    return 0;
}
