#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;

const int maxn = 100000+10;
struct POINT{
    int first,second,tag;
}point[maxn];
bool visited[maxn];
int dist[maxn];
inline int cost(const int a, const int b)
{
    return min(abs(point[a].first-point[b].first), abs(point[a].second-point[b].second));
}
pair<int, int> line[maxn*2];
bool cmpx(const POINT a, const POINT b)
{
    return a.first<b.first;
}
bool cmpy(const POINT a, const POINT b)
{
    return a.second<b.second;
}
bool cmptag(const POINT a, const POINT b)
{
    return a.tag<b.tag;
}
bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return cost(a.first, a.second)<cost(b.first, b.second);
}
int fa[maxn];
int djs(const int n)
{
    return n==fa[n]?n:fa[n]=djs(fa[n]);
}
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0; i<n; i++){
            scanf("%d %d",&point[i].first,&point[i].second);
            point[i].tag=i;
        }
        sort(point, point+n, cmpx);
        for(int i=0; i<n-1; i++){
            line[i].first=point[i].tag;    
            line[i].second=point[i+1].tag;
        }
        sort(point, point+n, cmpy);
        for(int i=0; i<n-1; i++){
            line[i+n-1].first=point[i].tag;
            line[i+n-1].second=point[i+1].tag;
        }
        sort(point, point+n, cmptag);
        for(int i=0; i<n; i++) fa[i]=i;
        sort(line, line+2*(n-1), cmp);
        long long ans = 0;
        for(int i=0; i<2*(n-1); i++){
            if(djs(line[i].first)==djs(line[i].second))continue;
            ans += cost(line[i].first,line[i].second);
            fa[djs(line[i].first)]=djs(line[i].second);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

