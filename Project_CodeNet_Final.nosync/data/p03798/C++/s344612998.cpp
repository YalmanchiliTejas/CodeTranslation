// clang-format off
#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (size_t i = 0; i < size_t(n); i++)
#define forn1(i,n) for (size_t i = 1; i <= size_t(n); i++)
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

const int MAX_N = 100000;
int n;
string s;
char ans[MAX_N];

char inv(char c) {
    if (c == 'S')
        return 'W';
    else if (c == 'W')
        return 'S';
    else
        assert(false);
}

bool sheep(int i) {
    return (s[i] == 'o' && ans[(i - 1 + n) % n] == ans[(i + 1 + n) % n])
        || (s[i] == 'x' && ans[(i - 1 + n) % n] != ans[(i + 1 + n) % n]);
}

bool wolf(int i) {
    return (s[i] == 'x' && ans[(i - 1 + n) % n] == ans[(i + 1 + n) % n])
        || (s[i] == 'o' && ans[(i - 1 + n) % n] != ans[(i + 1 + n) % n]);
}

bool check() {
    bool ok = true;
    forn(i, n) {
        ok &= ans[i] == 'S' ? sheep(i) : wolf(i);
    }

    return ok;
}

int main() {
    fastio();

    cin >> n >> s;

    forn(i0, 2) {
        ans[0] = !i0 ? 'S' : 'W';
        forn(in_1, 2) {
            ans[n - 1] = !in_1 ? 'S' : 'W';
            for (int i = 0; i < n - 2; i++) {
                char c = ans[(i - 1 + n) % n];
                if (ans[i] == 'S') {
                    ans[i + 1] = s[i] == 'o' ? c : inv(c);
                } else {
                    ans[i + 1] = s[i] == 'o' ? inv(c) : c;
                }
            }

            if (check()) {
                forn(i, n) {
                    cout << ans[i];
                }
                cout << endl;

                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}