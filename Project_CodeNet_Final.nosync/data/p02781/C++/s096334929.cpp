// clang-format off
#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define popcnt __builtin_popcount
#define ffs __builtin_ffs
#define ctz __builtin_ctz
#define clz __builtin_clz
#define all(a) (a).begin(), (a).end()
 
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using pll = pair<ll,ll>;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
using vl = vec<ll>;
template <typename T> using que = queue<T>;
template <typename T> using deq = deque<T>;

template <typename T> T id(T b) {return b;};
template <typename T> void chmax(T &x, T y) {if (x < y) x = y;}
template <typename T> void chmin(T &x, T y) {if (x > y) x = y;}
template <typename S, typename K> bool contains(S &s, K k) { return s.find(k) != s.end(); }
void fastio() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
constexpr ll TEN(int n) { if (n == 0) return 1LL; else return 10LL*TEN(n-1); }
// clang-format on

string n;
int k;

int main() {
    fastio();

    cin >> n >> k;

    ll ans = 0;

    int m = n.size();

    ll num = 1, denom = 1;
    for (int i = 1, j = m - 1; i <= k; i++, j--) {
        num *= j * 9;
        denom *= i;
    }

    ans += num / denom;

    for (int i = 1; i < n[0] - '0'; i++) {
        ll num = 1, denom = 1;
        for (int i = 1, j = m - 1; i <= k - 1; i++, j--) {
            num *= j * 9;
            denom *= i;
        }

        ans += num / denom;
    }

    if (k == 1) {
        ans++;
    }

    if (k == 2) {
        for (int i = 1; i < m; i++) {
            forn1(j, 9) {
                string t(m, '0');
                t[0] = n[0];
                t[i] = j + '0';
                if (t <= n) ans++;
            }
        }
    }

    if (k == 3) {
        for (int i = 1; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                forn1(l, 9) {
                    forn1(k, 9) {
                        string t(m, '0');
                        t[0] = n[0];
                        t[i] = l + '0';
                        t[j] = k + '0';
                        if (t <= n) ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}