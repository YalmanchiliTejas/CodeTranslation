#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
 
#define fst first
#define snd second
#define pb push_back
#define REP(i, a, b)  for(int i = (a), i##end = (b); i < i##end; ++i)
#define DREP(i, a, b) for(int i=(a-1), i##end = (b); i >=i##end; --i)
 
template <typename T> bool chkmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> bool chkmin(T& a, T b) { return a > b ? a = b, 1 : 0; }
 
const int N = 100000;
const int oo = 0x3f3f3f3f;
 
template<typename T> T read() {
    T n(0), f(1);
    char ch = getchar();
    for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) n = n * 10 + ch - 48; 
    return n * f;
}

int n;
vector<int> G[N + 5];

int dfs(int u, int f) {
    int cnt = 0;
    for(const int& v : G[u]) if(v != f) {
        cnt += (!dfs(v, u));
    }
    if(cnt >= 2) {
        puts("First");
        exit(0);
    }
    return cnt;
}

int main() {
#ifdef Wearry
    freopen("data.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
#endif 

    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        static int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v); G[v].pb(u);
    }
    if(!dfs(1, 0)) {
        puts("First");
    } else puts("Second");

    return 0;
}
