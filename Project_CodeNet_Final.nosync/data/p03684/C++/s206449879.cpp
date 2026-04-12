#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#define LL long long
#define FF(i,a,b) for(int i=a;i<=b;++i)
#define RR(i,a,b) for(int i=a;i>=b;--i)
#define SC(x) scanf("%d",&x)
#define SCC(x,y) scanf("%d%d",&x,&y)
#define SCCC(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SS(x) scanf("%s",x)
#define PR(x) printf("%d\n",x)
#define CL(a,b) memset(a,b,sizeof(a))
#define ll rt<<1
#define rr rt<<1|1
#define mid int m=(x+((y-x)>>1))
#define lson x,m,rt<<1
#define rson m+1,y,rt<<1|1
#define lowbit(x) (x&-x)
#define PB push_back
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define fi freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

const int N = 1e5 + 10;
const int inf = 1e9;

struct node{
    int u, v, w;
}e[N*3];
struct node2{
    int x, y, id;
}a[N];
bool cmp(node a, node b){
    return a.w < b.w;
}
bool cmp1(node2 a, node2 b){ return a.x < b.x; }
bool cmp2(node2 a, node2 b){ return a.y < b.y; }
int f[N];
int root(int x){
    if(f[x] == x) return x;
    return f[x] = root(f[x]);
}
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //IN;
#endif

    int cnt = 0;
    SC(n);
    FF(i, 0, n+1) f[i] = i;
    ///
    FF(i, 1, n){
        SCC(a[i].x, a[i].y);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp1);
    FF(i, 2, n){
        ++cnt;
        e[cnt].u = a[i-1].id; e[cnt].v = a[i].id;
        e[cnt].w = a[i].x - a[i-1].x;
    }
    sort(a + 1, a + n + 1, cmp2);
    FF(i, 2, n){
        ++cnt;
        e[cnt].u = a[i-1].id; e[cnt].v = a[i].id;
        e[cnt].w = a[i].y - a[i-1].y;
    }
    ///
    sort(e+1, e+1+cnt, cmp);
    LL ans = 0;
    FF(i, 1, cnt){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int rx = root(u), ry = root(v);
        if(rx != ry){
            f[rx] = ry;
            ans += w;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
