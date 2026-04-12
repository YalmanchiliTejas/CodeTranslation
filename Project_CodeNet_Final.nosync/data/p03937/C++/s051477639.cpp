#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int R, C, in[10][10], out[10][10];
char g[10][10];

bool ok (int r, int c) { return r>=0 && c>=0 && r<R && c<C && g[r][c] == '#'; }
void fail () { puts("Impossible"); exit(0); }

int main () {
        scanf("%d %d", &R, &C);
        fo(i, 0, R) scanf(" %s", g[i]);

        fo(r, 0, R) fo(c, 0, C) if (ok(r, c)) {
                in[r][c] = ok(r-1, c) + ok(r, c-1);
                out[r][c] = ok(r+1, c) + ok(r, c+1);
                if (!r && !c) {
                        if (in[r][c] != 0 || out[r][c] != 1) fail();
                        continue;
                }
                if (r==R-1 && c==C-1) {
                        if (in[r][c] != 1 || out[r][c] != 0) fail();
                        continue;
                }
                if (in[r][c] == 1 && out[r][c] == 1) continue;
                if (in[r][c] == 0 && out[r][c] == 0) continue;
                fail();
        }

        puts("Possible");
        return 0;
}

