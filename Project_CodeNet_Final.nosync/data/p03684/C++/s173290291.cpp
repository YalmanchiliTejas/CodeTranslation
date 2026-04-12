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

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
const int oo = 0x7fffffff;

template<typename T> T read() {
	T n(0), f(1);
	char ch = getchar();
	for( ;!isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
	for( ; isdigit(ch); ch = getchar()) n = n * 10 + ch - 48; 
    return n * f;
}

long long N, A, B;
struct node {
    int x, y, id;
}P[maxn];

struct Edge {
    int u, v, w;
    bool operator < (const Edge& rhs) const {
        return w < rhs.w;
    }
}E[maxn];

bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.y < b.y; }

int fa[maxn], cnt;
int find(int a) { return fa[a] == a ? a : fa[a] = find(fa[a]); }

int main() {
#ifdef Wearry
    freopen("data.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
#endif

    cin >> N;
    REP(i, 0, N) fa[i] = i;
    REP(i, 0, N) {
        P[i].id = i;
        cin >> P[i].x >> P[i].y;
    }

    sort(P, P + N, cmp1);
    REP(i, 0, N-1) { E[cnt++] = (Edge) { P[i].id, P[i+1].id, P[i+1].x - P[i].x }; }

    sort(P, P + N, cmp2);
    REP(i, 0, N-1) { E[cnt++] = (Edge) { P[i].id, P[i+1].id, P[i+1].y - P[i].y }; }

    int ans = 0;
    sort(E, E + cnt);

    REP(i, 0, cnt) {
        int u = E[i].u, v = E[i].v;
        int fu = find(u), fv = find(v);
        if(fu != fv) {
            ans += E[i].w;
            fa[fu] = fv;
        }
    }

    cout << ans << endl;
    return 0;
}
