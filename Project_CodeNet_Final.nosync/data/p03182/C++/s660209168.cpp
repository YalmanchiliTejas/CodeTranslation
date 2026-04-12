#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 200005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define pii pair<int, int>
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, m;
LL t[MAXN*4], tag[MAXN*4];
vector<pii> vec[MAXN];

void up(int root)
{
    t[root]=max(t[ls], t[rs])+tag[root];
}

void update(int root, int l, int r, int x, int y, LL k)
{
    //printf("%d %d %d %d!!!\n", root, l, r, k);
    if(l>y || r<x) return;
    if(l>=x && r<=y)
    {
        t[root]+=k, tag[root]+=k;
        return ;
    }
    update(ls, l, mid, x, y, k);
    update(rs, mid+1, r, x, y, k);
    up(root);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1; i<=m; ++i)
    {
        int l, r, a;
        scanf("%d%d%d", &l, &r, &a);
        vec[r].push_back(make_pair(l, a));
    }
    for(rint i=1; i<=n; ++i)
    {
        update(1, 1, n, i, i, t[1]);
        for(rint j=0; j<vec[i].size(); ++j)
        {
            pii temp=vec[i][j];
            update(1, 1, n, temp.first, i, temp.second);
        }
    }
    printf("%lld\n", max(0LL, t[1]));
}
