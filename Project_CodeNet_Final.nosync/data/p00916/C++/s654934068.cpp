#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RFOR(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for (int i = (int)(n - 1); i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(a) ((int)(a).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define SQ(x) ((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int H = 101;
const int W = 101;

long long v[H][W];

const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

void dfs(int x, int y, long long c, vvb &G) {
    G[y][x] = true;
    REP(i, 4) {
        int sx = x + dx[i], sy = y + dy[i];
        if (0 <= sx && sx < W && 0 <= sy && sy < H) {
            if (v[sy][sx] == c && !G[sy][sx]) dfs(sx, sy, c, G);
        }
    }
}

int main() {
    int N;
    while (cin >> N, N) {
        memset(v, 0, sizeof(v));
        vi L, T, R, B;
        set<int> Ys, Xs;
        REP(i, N) {
            int l, t, r, b;
            cin >> l >> t >> r >> b;
            L.push_back(l);
            T.push_back(t);
            R.push_back(r);
            B.push_back(b);
            Ys.insert(t);
            Ys.insert(b);
            Xs.insert(l);
            Xs.insert(r);
        }
        Ys.insert(-1);
        Ys.insert(1e6 + 10);
        Xs.insert(-1);
        Xs.insert(1e6 + 10);
        vi Y(ALL(Ys));
        vi X(ALL(Xs));
        set<long long> S;
        REP(i, N) {
            int xl = lower_bound(ALL(X), L[i]) - X.begin();
            int xr = lower_bound(ALL(X), R[i]) - X.begin();
            int yt = lower_bound(ALL(Y), T[i]) - Y.begin();
            int yb = lower_bound(ALL(Y), B[i]) - Y.begin();
            FOR(x, xl, xr) {
                FOR(y, yb, yt) {
                    long long bit = (1LL << i);
                    v[y][x] |= bit;
                }
            }
        }

        int cnt = 0;
        vvb G(H, vb(W));
        REP(y, H) REP(x, W) {
            if (!G[y][x]) {
                cnt++;
                dfs(x, y, v[y][x], G);
            }
        }
        cout << cnt << endl;
    }
}