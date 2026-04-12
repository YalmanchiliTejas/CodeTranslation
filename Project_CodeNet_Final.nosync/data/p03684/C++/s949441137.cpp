#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define x first
#define y second

#define MAXN 100009

std::pair <int, int> ix[MAXN], igrec[MAXN];

int t[MAXN], x[MAXN], y[MAXN];

int sef(int x){
    if ( x== t[x]) return x;
    else return t[x] = sef(t[x]);
}

struct myc{
    int x, y, z;
    inline bool operator < (const myc & u) const {
        return x < u.x;
    }
}e[2 * MAXN];

inline myc makeMyc(int _x, int _y, int _z) {
    myc aux;
    aux.x = _x;
    aux.y = _y;
    aux.z = _z;
    return aux;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        ix[i].x = x[i];
        ix[i].y = i;
        igrec[i].x = y[i];
        igrec[i].y = i;
    }

    std::sort(ix + 1, ix + n + 1);
    std::sort(igrec + 1, igrec + n + 1);

    int k =0;
    for (int i = 2; i <= n; i++)
        e[++k] = makeMyc(ix[i].x - ix[i-1].x, ix[i].y, ix[i - 1].y);
    for (int i = 2; i <= n; i++)
        e[++k] = makeMyc(igrec[i].x - igrec[i-1].x, igrec[i].y, igrec[i - 1].y);

    std::sort(e +1, e +k + 1);

    for (int i = 1; i <= n; i++)
        t[i] = i;

    long long ans = 0;

    for (int i = 1; i <= k; i++) {
        //printf("%d %d %d\n", e[i].x, e[i].y, e[i].z);
        if(sef(e[i].y) != sef(e[i].z)) {
            ans += e[i].x;
            t[sef(e[i].y)] = sef(e[i].z);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
