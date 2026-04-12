#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll dp[401][201][201];
int A[201][201];

bool same(int ay, int ax, int by, int bx) {
    return ay == by&&ax == bx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    while(cin >> H >> W) {
        rep(y, H)rep(x, W)cin >> A[y][x];

        MEM(dp, -1);
        dp[0][0][0] = A[0][0];

        rep(s, H + W - 2) {
            rep(ay, H) {
                if(ay > s)continue;
                int ax = s - ay;
                if(ax < 0 || ax >= W)continue;
                rep(by, H) {
                    if(by > s)continue;

                    int bx = s - by;
                    if(bx < 0 || bx >= W)continue;

                    ll z = dp[s][ay][by];
                    if(z == -1)continue;

                    // 下,下
                    if(ay < H - 1 && by < H - 1) {
                        int nay = ay + 1;
                        int nby = by + 1;
                        ll w = z + A[nay][ax] + A[nby][bx];
                        if(same(nay, ax, nby, bx)) {
                            w -= A[nay][ax];
                        }
                        smax(dp[s + 1][nay][nby], w);
                    }

                    // 下,右
                    if(ay < H - 1 && bx < W - 1) {
                        int nay = ay + 1;
                        int nbx = bx + 1;
                        ll w = z + A[nay][ax] + A[by][nbx];
                        if(same(nay, ax, by, nbx)) {
                            w -= A[nay][ax];
                        }
                        smax(dp[s + 1][nay][by], w);
                    }

                    // 右,下
                    if(ax < W - 1 && by < H - 1) {
                        int nax = ax + 1;
                        int nby = by + 1;
                        ll w = z + A[ay][nax] + A[nby][bx];
                        if(same(ay, nax, nby, bx)) {
                            w -= A[ay][nax];
                        }
                        smax(dp[s + 1][ay][nby], w);
                    }

                    // 右,右
                    if(ax < W - 1 && bx < W - 1) {
                        int nax = ax + 1;
                        int nbx = bx + 1;
                        ll w = z + A[ay][nax] + A[by][nbx];
                        if(same(ay, nax, by, nbx)) {
                            w -= A[ay][nax];
                        }
                        smax(dp[s + 1][ay][by], w);
                    }
                }
            }
        }

        cout << dp[H+W-2][H - 1][H - 1] << endl;
    }
}