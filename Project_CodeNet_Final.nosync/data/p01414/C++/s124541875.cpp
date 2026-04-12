#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const char of[] = "RGB";

int N, H[20], W[20];
char f[4][4];
int Qi, Qn, Q[65536], dp[65536];
int m, mask[2048], chg[256][4];

int main() {
    scanf("%d", &N);
    rep(i, N) scanf("%d%d", H+i, W+i);
    rep(i, 4) rep(j, 4) scanf(" %c", f[i]+j);
    memset(dp, -1, sizeof(dp));
    rep(k, N) {
        for(int i=-4; i<4; i++) for(int j=-4; j<4; j++) {
            int b = 0;
            rep(x, 4) rep(y, 4) if(i<=x && x<i+H[k] && j<=y && y<j+W[k]) {
                b |= 1<<(x*4+y);
            }
            mask[m++] = b;
        }
    }
    sort(mask, mask+m);
    m = unique(mask, mask+m)-mask;
    rep(i, m) rep(x, 4) rep(y, 4) if(mask[i]&(1<<(x*4+y))) {
        rep(k, 3) if(f[x][y]==of[k]) chg[i][k] |= 1<<(x*4+y);
    }
    dp[0] = 0;
    Q[Qn++] = 0;
    while(Qi<Qn && dp[65535]==-1) {
        const int cur = Q[Qi++];
        rep(i, m) rep(k, 3) {
            const int nxt = (cur&~mask[i]) | chg[i][k];
            if(dp[nxt]==-1) {
                dp[nxt] = dp[cur]+1;
                Q[Qn++] = nxt;
            }
        }
    }
    printf("%d\n", dp[65535]);
    return 0;
}