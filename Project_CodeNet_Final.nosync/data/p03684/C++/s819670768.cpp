

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for ( int i=1; i<=int(n); i++ )  
#define MP make_pair
#define PB push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;
typedef pair<int, int> pii;
typedef long double LD;
const int INF = 0x3f3f3f3f;

template <class T>  
inline bool RD(T &ret) {  
        char c; int sgn;  
        if (c = getchar(), c == EOF) return 0;  
        while (c != '-' && (c<'0' || c>'9')) c = getchar();  
        sgn = (c == '-') ? -1 : 1 , ret = (c == '-') ? 0 : (c - '0');  
        while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');  
        ret *= sgn;  
        return 1;  
}  
template <class T>  
inline void PT(T x) {  
        if (x < 0) putchar('-') ,x = -x;  
        if (x > 9) PT(x / 10);  
        putchar(x % 10 + '0');  
}

const int N = 1e5 + 100;
pii a[N], b[N];
pair<int, pii> es[N << 1];
int fa[N];
int getf(int x) { return x == fa[x] ? x : fa[x] = getf(fa[x]); }
int main() {
    int ecnt = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        scanf("%d %d", &a[i].X, &b[i].X);
        a[i].Y = b[i].Y = i;
    }
    for(int i = 1; i <= n; i ++) fa[i] = i;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for(int i = 1; i < n; i ++) {
        es[++ ecnt] = pair<int, pii>(a[i + 1].X - a[i].X, 
                pii(a[i + 1].Y, a[i].Y));
        es[++ ecnt] = pair<int, pii>(b[i + 1].X - b[i].X,
                pii(b[i + 1].Y, b[i].Y)); 
    }
    LL ans = 0;
    sort(es + 1, es + ecnt + 1);
    for(int i = 1; i <= ecnt; i ++) {
        int u = es[i].Y.X, v = es[i].Y.Y;
        if(getf(u) == getf(v)) continue;
        ans += es[i].X;
        fa[getf(u)] = getf(v);
    }
    printf("%lld\n", ans);
}
