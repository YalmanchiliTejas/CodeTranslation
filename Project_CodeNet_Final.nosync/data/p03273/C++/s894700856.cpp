#include <bits/stdc++.h>

using namespace std;
#define next _next
#define y1 _y1
#define y2 _y2
#define lowbit(x) (x&(-x))
#define lc ((rt)<<1)
#define rc ((rt)<<1|1)
#define mid  ((l+r)>>1)
#define clr(a, b) memset(a,b,sizeof(a))

#ifdef __LOCAL_DEBUG__
#define _debug(fmt, ...)fprintf(stdout,"\033[94m%s: " fmt "\n\033[0m",__func__,##__VA_ARGS__)
#define debug(a) cerr <<"\033[94m" <<#a << "\033[0m = "<< a << endl;
#define debug_loop(v) {cerr <<#v;for(auto x:v) cerr <<"\033[94m " <<x<<"\033[0m";cerr<<endl;}
#else
#define _debug(...)((void)0)
#define debug(a)((void)0)
#define debug_loop(v)((void)0)
#endif

typedef long long ll;
const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = static_cast<int>(1e6 + 7);

int main() {
#ifndef __LOCAL_DEBUG__
    ios::sync_with_stdio(false), cin.tie(nullptr);
#endif
    char g[101][101];
    int flag_n[101], flag_m[101];
    int n, m;
    clr(flag_m, 0);
    clr(flag_n, 0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '#') {
                flag_n[i] = 1;
                break;
            }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (g[j][i] == '#') {
                flag_m[i] = 1;
                break;
            }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (flag_m[j] == 0 || flag_n[i] == 0) continue;
            cout << g[i][j];
        }
        if (flag_n[i]) cout << endl;
    }
}