#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define do(i, j, k) for(int i = j; i <= (k); i ++)
#define open(i, j, k) for(int i = j; i < (k); i ++)
#define dec(i, j, k) for(int i = j; i >= (k); i --)
#define mfil(x, k) memset(x, k, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y, true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y, true) : false; }
struct __init { __init()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cout.precision(16); cout << fixed;
    srand(time(0) ^ ul(new char));
} } static __init__;
/* default code ends here */

const int maxn = 1e5 + 10;
int n;
vi h[maxn];
int du[maxn];
bool vis[maxn];

priority_queue<pii, vector<pii>, greater<pii>> pq;

void fir()
{
    cout << "First\n";
    exit(0);
}
void sec()
{
    cout << "Second\n";
    exit(0);
}

int find_head(int x)
{
    if(du[x] > 1)
        return x;
    vis[x] = true;
    int y = -1;
    for(int v : h[x])
        if(!vis[v])
            y = v;
    if(y == -1)
        return -1;
    du[y] --;
    return find_head(y);
}

int main()
{
    cin >> n;
    for(int i = 1, u, v; i < n; i ++)
    {
        cin >> u >> v;
        h[u].pb(v);
        h[v].pb(u);
        du[u] ++;
        du[v] ++;
    }
    do(i, 1, n)
        if(du[i] == 1)
            pq.push({du[h[i][0]], i});
    while(!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        int x = p.se;
        if(vis[x])
            continue;
        vis[x] = true;
        int y = -1;
        for(int v : h[x])
            if(!vis[v])
                y = v;
        //cerr << "OP : " << x << ' ' << y << ' ';
        if(y == -1 || du[y] >= 3)
            fir();
        //y = find_head(x);
        //cerr << y << '\n';
        vis[y] = true;
        for(int v : h[y])
            if(!vis[v])
            {
                du[v] --;
                if(du[v] == 0)
                    fir();
                else if(du[v] == 1)
                {
                    for(int vv : h[v])
                        if(!vis[vv])
                            pq.push({du[vv], v});
                }
                else if(du[v] == 2)
                {
                    for(int vv : h[v])
                        if(!vis[vv] && du[vv] == 1)
                            pq.push({du[v], vv});
                }
            }
        // for(int v : h[y])
        //     if(!vis[v] && du[v] == 1)
        //     {
        //         pq.push({du[y], v});
        //     }
    }
    sec();
    return 0;
}