#include<bits/stdc++.h>

using namespace std;
const int N = 100000 + 10;
typedef long long ll;
int root[N];
int Find(int x)
{
    return x == root[x] ? x : root[x] = Find(root[x]);
}

int join(int x, int y)
{
    int a = Find(x), b = Find(y);
    if(a != b)
    {
        root[a] = b;
        return 1;
    }
    return 0;
}
struct node
{
    int x, y, w;
}p[N];

int cmp1(node a, node b)
{
    return a.x < b.x;
}

int cmp2(node a, node b)
{
    return a.y < b.y;
}
typedef pair<int, int> P;
vector<pair<int, P> > path;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
        scanf("%d%d", &p[i].x, &p[i].y), p[i].w = i, root[i] = i;
    sort(p, p+n, cmp1);
    for(int i = 1; i<n; i++)
    {
        int x = p[i].w;
        int y = p[i-1].w;
        int z = abs(p[i].x - p[i-1].x);
        path.push_back(make_pair(z, make_pair(x, y)));
    }

    sort(p, p+n, cmp2);
    for(int i = 1; i<n; i++)
    {
        int x = p[i].w;
        int y = p[i-1].w;
        int z = abs(p[i].y - p[i-1].y);
        path.push_back(make_pair(z, make_pair(x, y)));
    }
    sort(path.begin(), path.end());
    int ans = 0;
    for(int i = 0; i<path.size(); i++)
    {
        if(join(path[i].second.second, path[i].second.first))
           ans += path[i].first;
    }
    cout<<ans<<endl;
    return 0;
}
