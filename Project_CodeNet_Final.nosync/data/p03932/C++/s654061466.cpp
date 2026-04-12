#include <bits/stdc++.h>
using namespace std;

#define len(x)  (int((x).size()))
#define append push_back
#define pp make_pair
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define kk(n)    ff(k, n)
#define xx(n)    ff(x, n)
#define yy(n)    ff(y, n)
#define ii(n)    ff(i, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define kkk(a, b) fff(k, a, b)
#define xxx(a, b) fff(x, a, b)
#define yyy(a, b) fff(y, a, b)
#define iii(a, b) fff(i, a, b)
#define bb begin()
#define ee end()
#define uu first
#define vv second
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define zz(array, byte)   memset(array, byte, sizeof(array));

using LL = long long;
using DD = long double;
using pii = pair<int, int>;



const LL  INFLL  = 0x7f7f7f7f7f7f7f7fLL;
const int INFint = 0x7f7f7f7f;  //Works with memset(..).
 
     




int main() {
    //ios_base::sync_with_stdio(false);     cin.tie(NULL);
    //cout << '\n';
    cout.precision(16);
    

    int h, w;
    cin >> h >> w;
    vector<vector<int> > grid(h, vector<int>(w, 0));
    yy (h)
    xx (w)
        cin >> grid[y][x];

    map<pii, int> best;
    best[pp(0, 0)] = grid[0][0];
    ii (h + w - 2) {
        map<pii, int> next;
        fe (it, best) {
            int x1 = it->uu.uu;
            int x2 = it->uu.vv;
            int y1 = i - x1;
            int y2 = i - x2;
            xx (2) {
                int x1n = x1 + x;
                int y1n = y1 + (1-x);
                if (! (x1n < w && y1n < h))
                    continue;
                yy (2) {
                    int x2n = x2 + y;
                    int y2n = y2 + (1-y);
                    if (! (x2n < w && y2n < h))
                        continue;

                    int here = grid[y1n][x1n];
                    if (x1n != x2n)
                        here += grid[y2n][x2n];
                    pii key = pp(min(x1n, x2n), max(x1n, x2n));
                    next[key] = max(next[key], it->vv + here);
                    //printf("put %d %d %d\n", x1n, x2n, it->vv + here);
                }
            }
        }
        //printf("\n");
        swap(best, next);
    }
    int rr = 0;
    fe (it, best) {
        rr = it->vv;
    }

    cout << rr << '\n';
    

    return 0;
}

