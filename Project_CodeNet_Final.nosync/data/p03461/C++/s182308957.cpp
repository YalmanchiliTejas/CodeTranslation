#include <cstring>
#include <cstdio>
#include <algorithm>
const int INF = 0x3f3f3f3f;
using namespace std;

const int MAXV = 15;
const int MAXN = 105;
int A, B, D[MAXV][MAXV], F[MAXN][MAXN];

const int PointS = 1;
const int PointT = 2;
int NPoint = 2, NSide = 0, pointX[MAXN], pointY[MAXN];
struct side { int u, v, d; } S[MAXN * MAXN];
inline void link(int u, int v, int d) { S[++NSide] = (side){u, v, d}; } //-1: X, -2: Y

int main() {
    int x, y, a, b;
    scanf("%d%d", &A, &B);
    for(x = 1; x <= A; x++) for(y = 1; y <= B; y++) scanf("%d", &D[x][y]);

    //construct
    for(a = 0; a <= 100; a++) for(b = 0; b <= 100; b++) {
        for(x = 1; x <= A; x++) for(y = 1; y <= B; y++) F[a][b] = max(F[a][b], D[x][y] - a * x - b * y);
    }
    //check if ok
    bool Succ = 1;
    for(x = 1; x <= A; x++) for(y = 1; y <= B; y++) {
        int dist = INF;
        for(a = 0; a <= 100; a++) for(b = 0; b <= 100; b++) dist = min(dist, a * x + b * y + F[a][b]);
        if(dist != D[x][y]) Succ = 0;
    }
    if(!Succ) printf("Impossible");
    else {
        //construct
        pointX[0] = PointS; for(a = 1; a <= 100; a++) pointX[a] = ++NPoint, link(pointX[a - 1], pointX[a], -1);
        pointY[0] = PointT; for(b = 1; b <= 100; b++) pointY[b] = ++NPoint, link(pointY[b], pointY[b - 1], -2);
        for(a = 0; a <= 100; a++) for(b = 0; b <= 100; b++) link(pointX[a], pointY[b], F[a][b]);
        //print
        printf("Possible\n%d %d\n", NPoint, NSide);
        for(int i = 1; i <= NSide; i++) {
            if(S[i].d < 0) printf("%d %d %c\n", S[i].u, S[i].v, (S[i].d == -1) ? 'X' : 'Y');
            else printf("%d %d %d\n", S[i].u, S[i].v, S[i].d);
        }
        printf("%d %d", PointS, PointT);
    }
}