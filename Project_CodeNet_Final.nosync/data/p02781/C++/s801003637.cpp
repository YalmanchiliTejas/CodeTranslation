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
ll le[100][5];
ll nongt[100][5];

int main() {
    fastio();

    cin >> n >> k;

    int m = n.size();

    le[0][0] = n[0] != '0';
    le[0][1] = max(0, n[0] - '0' - 1);
    nongt[0][1] = 1;

    forn1(i, m - 1) {
        forn(j, k + 1) {
            // use 0
            le[i][j] += le[i - 1][j] + (n[i] == '0' ? 0 : nongt[i - 1][j]);
            // use 1-9
            le[i][j + 1] += le[i - 1][j] * 9;
            if (n[i] > '0')
                le[i][j + 1] += nongt[i - 1][j] * (n[i] - '0' - 1);

            if (n[i] == '0') {
                nongt[i][j] += nongt[i - 1][j];
            } else {
                nongt[i][j + 1] += nongt[i - 1][j];
            }
        }
    }

    cout << le[m - 1][k] + nongt[m - 1][k] << endl;

    return 0;
}