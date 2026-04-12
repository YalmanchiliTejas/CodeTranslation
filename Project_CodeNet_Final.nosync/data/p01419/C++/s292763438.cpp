#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef priority_queue<pii, vp, greater<pii> > piq;

const int N = 55;
const int M = 1010;
const int K = 100010;
const int LIT = 2500;
const int INF = 1 << 28;
const int base = 137;
const double eps = 1e-10;
const int dir[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int dir2[10][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
const int ABS(int a) {return a > 0 ? a : -a;}

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

const pii nonvis = mp(-1, -1);
int n, m, r, cnt, use[N][N], on[N][N], off[N][N];
vi stp[N][N];
char g[N][N];
vp v;
ll res;

void init()
{
    memset(g, 0, sizeof(g));
    for(int i = 0; i < n; i++) scanf("%s", &g[i]);
    
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    scanf("%d", &use[i][j]);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    scanf("%d", &on[i][j]);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    scanf("%d", &off[i][j]);
    
    v = vp(r);
    for(int i = 0; i < r; i++) scanf("%d %d", &v[i].fst, &v[i].snd);
    
    for(int i = 0; i < N; i++) for(int j = 0; j < m; j++) stp[i][j].clear();
}

void getroute(int p)
{
    pii vis[N][N];
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) vis[i][j] = nonvis;
    queue<pii> que;
    que.push(v[p]);
    vis[v[p].fst][v[p].snd] = mp(-2, -2);
    
    while(!que.empty())
    {
        pii pre = que.front();
        que.pop();
        if(pre == v[p + 1])
        {
            stack<pii> sta;
            while(1)
            {
                sta.push(pre);
                if(pre == v[p]) break;
                pre = vis[pre.fst][pre.snd];
            }
            if(p) sta.pop();
            while(!sta.empty())
            {
                int x = sta.top().fst, y = sta.top().snd;
                sta.pop();
                cnt++;
                stp[x][y].pb(cnt);
            }
            break;
        }
        int x = pre.fst, y = pre.snd;
        for(int i = 0; i <= 3; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(g[xx][yy] == '#' || vis[xx][yy] != nonvis) continue;
            que.push(mp(xx, yy));
            vis[xx][yy] = pre;
        }
    }
}

void solve()
{
    cnt = 0; res = 0;
    for(int i = 1; i < r; i++) getroute(i - 1);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //printf("place = %d %d\n", i, j);
            int s = stp[i][j].size();
            if(!s) continue;
            res += on[i][j] + off[i][j];
            for(int k = 1; k < s; k++) //printf("%d ", stp[i][j][k]);
            {
                ll gap = stp[i][j][k] - stp[i][j][k - 1];
                ll t1 = gap * use[i][j];
                ll t2 = on[i][j] + off[i][j];
                res += min(t1, t2);
            }
            //printf("\n");
        }    
    }
    
    cout<<res<<endl;
    //for(int i = 0; i < cnt; i++) printf("%d %d\n", route[i][0], route[i][1]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(cin>>n>>m>>r)
    {
        init();
        solve();
    }
    //while(1);
} 