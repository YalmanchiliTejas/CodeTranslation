#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, par[N], sz[N];
struct  poi{
    int x, y, idx;
}   p[N];
struct  edge    {
    int x, y, w;
}   e;
vector<edge>    E, MST;
int ans = 0;
bool cmp1(poi A,poi B)  {
    return A.x < B.x;
}
bool cmp2(poi A,poi B)  {
    return A.y < B.y;
}
bool cmp(edge e1,edge e2)   {
    return  e1.w < e2.w;
}
int findSet(int x)  {
    return  par[x] == x ? x : par[x] = findSet(par[x]);
}
void unionSet(int x,int y) {
    int a = findSet(x);
    int b = findSet(y);
    if(a == b)  return;
    if(sz[a] < sz[b])   swap(a,b);
    par[b] = a; sz[a] += sz[b];
}
int main()  {
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)   {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
        par[i] = i;
        sz[i] = 1;
    }
    sort(p + 1,p + 1 + n,cmp1);
    for(int i = 1 ; i < n ; ++i)   {
        e.x = p[i].idx;
        e.y = p[i + 1].idx;
        e.w = p[i + 1].x - p[i].x;
        E.push_back(e);
    }
    sort(p + 1,p + 1 + n,cmp2);
    for(int i = 1 ; i < n ; ++i)   {
        e.x = p[i].idx;
        e.y = p[i + 1].idx;
        e.w = p[i + 1].y - p[i].y;
        E.push_back(e);
    }
    sort(E.begin(),E.end(),cmp);
    int i = 0;
    while(MST.size() < n - 1)   {
        int x = E[i].x, y = E[i].y, W = E[i].w;
        ++i;
        if(findSet(x) == findSet(y))    continue;
        ans += W;   MST.push_back(E[i - 1]);
        unionSet(x,y);
    }
    cout << ans << endl;
}
