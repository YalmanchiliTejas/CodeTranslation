#include <cassert>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); puts("");}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(x); return v;}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}

#define all(x)  (x).begin(),(x).end()
#define tr(c, it)   for(auto it=c.begin(); it!=c.end(); it++)
#define clr(a, b)   memset(a, b, sizeof(a))
#define forn(i, n)   for(int i=0; i<n; i++)

const double eps = 1e-6;

const int N = 100010;

int n;
struct Node{
    int x, y, idx;
}p[N];

bool cmp1(const Node& a, const Node& b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(const Node& a, const Node& b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b. y;
}

int head[N], e;
struct E{
    int u, v, w, next;
}edge[N << 1];

void addedge(int u, int v, int w){
    edge[e].u = u;
    edge[e].w = w;
    edge[e].v = v, edge[e].next = head[u];
    head[u] = e++;
}

bool cmp3(const E& a, const E& b){
    return a.w < b.w;
}




int pa[N];
int find(int x)	{while (x != pa[x]) pa[x] = pa[pa[x]], x = pa[x];return x;}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif

    //scanf("%d",&T);


    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            p[i].idx = i;
            scanf("%d%d",&p[i].x, &p[i].y);
        }

        clr(head, -1), e = 0;

        sort(p+1, p+1+n, cmp1);
        for(int i=1; i<n; i++)
        {
            int w = p[i+1].x - p[i].x;
            addedge(p[i].idx, p[i+1].idx, w);
            //addedge(p[i+1].idx, p[i].idx, w);
        }

        sort(p+1, p+1+n, cmp2);
        for(int i=1; i<n; i++)
        {
            int w = p[i+1].y - p[i].y;
            addedge(p[i].idx, p[i+1].idx, w);
            //addedge(p[i+1].idx, p[i].idx, w);
        }

        LL ans = 0;
        for(int i=1; i<=n; i++)
            pa[i] = i;

        sort(edge, edge+e, cmp3);
        for(int i=0; i<e; i++)
        {
            int a = edge[i].u;
            int b = edge[i].v;

            int fa = find(a);
            int fb = find(b);
            if(fa == fb) continue;

            pa[fb] = fa;
            ans += edge[i].w;
        }
        cout << ans << endl;





    }
    return 0;
}