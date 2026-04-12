// #define FNAME "template"

#define NDEBUG

#include <bits/stdc++.h>
using namespace std;

typedef long long inte;
const int maxn = 100005;

#ifndef NDEBUG
#    define dprint(x) (cerr << (#x) << " = "<< (x) << endl)
#else
#    define dprint(x) (NULL)
#endif

template<typename T>
inline void readFig(T& x)
{
#   ifdef FTREAD
        static int c = 0;
        int op = 1;
        x = 0;
        while (!isdigit(c)) {
            if (c == '-')
                op = -1;
            c = getchar();
        }
        while (isdigit(c)) {
            x *= 10;
            x += c - '0';
            c = getchar();
        }
        x *= op;
#   else
        cin >> x;
#   endif
}

int N, M;
struct Edge {
    int u, v, w;
} edges[maxn * 2];
inline bool operator < (const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int par[maxn];
int getPar(int x)
{
    static int st[maxn];
    int stop = 0;
    while (par[x] != x) {
        x = par[x];
        st[stop++] = x;
    }
    while (stop--)
        par[st[stop]] = x;
    return x;
}
inline inte genMST()
{
    for (int i = 1; i <= N; ++i)
        par[i] = i;
    int cnt = 0;
    inte ans = 0;
    for (int i = 1; i <= M; ++i) {
        int u = getPar(edges[i].u), v = getPar(edges[i].v);
        if (u != v) {
            par[u] = v;
            ++cnt;
            ans += edges[i].w;
            dprint(ans);
        }
    }
    //assert(cnt == N - 1);
    return ans;
}

struct City {
    int x, y, id;
} cities[maxn];

inline bool compx(const City &a, const City &b)
{
    return a.x < b.x;
}
inline bool compy(const City &a, const City &b)
{
    return a.y < b.y;
}
inline int getdis(const City &a, const City &b)
{
    return min(abs(a.x - b.x), abs(a.y - b.y));
}

inline void solve()
{
    readFig(N);
    for (int i = 1; i <= N; ++i) {
        readFig(cities[i].x); readFig(cities[i].y);
        cities[i].id = i;
    }
    sort(cities + 1, cities + N + 1, compx);
    for (int i = 1; i < N; ++i) {
        edges[++M].u = cities[i].id;
        edges[M].v = cities[i + 1].id;
        edges[M].w = getdis(cities[i], cities[i + 1]);
    }
    sort(cities + 1, cities + N + 1, compy);
    for (int i = 1; i < N; ++i) {
        edges[++M].u = cities[i].id;
        edges[M].v = cities[i + 1].id;
        edges[M].w = getdis(cities[i], cities[i + 1]);
    }
    sort(edges + 1, edges + M + 1);
    cout << genMST() << endl;
}

signed main()
{
#   ifdef FNAME
        freopen(FNAME".in", "r", stdin);
        freopen(FNAME".out", "w", stdout);
#   endif
#   ifndef FTREAD
    	ios::sync_with_stdio(false);
    	cin.tie(0);
#   endif

#   ifdef MULTEST
        int T;
        readFig(T);
        while (T--)
            solve();
#   else
        solve();
#   endif

#   ifdef FNAME
        fclose(stdin);
        fclose(stdout);
#   endif
    	return 0;
}

