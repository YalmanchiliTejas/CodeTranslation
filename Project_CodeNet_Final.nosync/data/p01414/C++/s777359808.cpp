#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RFOR(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for (int i = (int)(n - 1); i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SZ(a) ((int)(a).size())
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef pair<int, int> pii;

struct P {
    int cost;
    uint16_t bit;
};

char colorchar[] = {'R', 'G', 'B'};
char G[1<<16];

int main() {
    int N;
    cin >> N;
    vector<pii> stamp(N);
    REP(i, N) {
        cin >> stamp[i].second >> stamp[i].first;
    }
    vvc field(4, vc(4));
    REP(y, 4) REP(x, 4) {
        cin >> field[y][x];
    }

    fill_n((char *)G, 1<<16, -1);
    uint16_t goal = (1<<16)-1;

    queue<uint16_t> que;
    G[0] = 0;
    que.push(0);
    while (!que.empty()) {
        uint16_t p = que.front(); que.pop();
        if (p == goal) {
            printf("%d\n", G[p]);
            break;
        }
        REP(i, N) {
            FOR(ly, -stamp[i].second+1, 4) FOR(lx, -stamp[i].first+1, 4) {
                int rx = lx + stamp[i].first, ry = ly + stamp[i].second;
                uint16_t bit[3] = {p, p, p};
                FOR(sy, ly, ry) FOR(sx, lx, rx) {
                    if (0 <= sx && sx < 4 && 0 <= sy && sy < 4) {
                        REP(j, 3) {
                            int k = 4*sy+sx;
                            if (field[sy][sx] == colorchar[j]) {
                                bit[j] |= 1<<k;
                            } else {
                                bit[j] &= ~(1<<k);
                            }
                        }
                    }
                }
                REP(j, 3) {
                    if (G[bit[j]] == -1) {
                        G[bit[j]] = G[p]+1;
                        que.push(bit[j]);
                    }
                }
            }
        }
    }
}