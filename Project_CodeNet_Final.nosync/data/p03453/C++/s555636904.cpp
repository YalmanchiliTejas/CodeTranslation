#include<bits/stdc++.h>
using namespace std;
const int MAXN = 101010;
const int MOD = 1e9+7;
int N, M;
vector<pair<int,int> > conn[MAXN];
int S, T;
bool vis[MAXN];
long long mindistS[MAXN];
long long mindistT[MAXN];
long long wayfromS[MAXN];
long long wayfromT[MAXN];

void D( int st, long long mindist[], long long way[])
{
    vector<int> rabbit;
    memset(vis, 0, sizeof(vis));
    using pli = pair<long long, int>;
    priority_queue<pli,vector<pli>,greater<pli>> Q;
    Q.emplace(0, st);
    while(!Q.empty())
    {
        long long dist; int a; tie(dist, a) = Q.top(); Q.pop();
        if(vis[a]) continue; vis[a] = true;
        rabbit.push_back(a);
        mindist[a] = dist;
        for(auto x: conn[a])
            Q.emplace(dist+x.second, x.first);
    }
    way[st] = 1;
    for(auto x: rabbit)
    {
        if(x==st) continue;
        for(auto tmp: conn[x])
        {
            int xydist, y; tie(y, xydist) = tmp;
            if(mindist[y] + xydist == mindist[x])
            {
                //printf("%d %d %d\n",st, x, y);
                way[x] += way[y];
                way[x] %= MOD;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    for(int i=0; i<M; ++i)
    {
        int s, e, x;
        scanf("%d%d%d", &s, &e, &x);
        conn[s].emplace_back(e, x);
        conn[e].emplace_back(s, x);
    }
    vector<int> Sorder, Torder;
    D(S, mindistS, wayfromS);
    D(T, mindistT, wayfromT);
    /*
    for(int i=1; i<=N; ++i)
    {
        printf("%3d->%3d: %3lld/%3lld\n", S, i, mindistS[i], wayfromS[i]);
    }
    for(int i=1; i<=N; ++i)
    {
        printf("%3d->%3d: %3lld/%3lld\n", T, i, mindistT[i], wayfromT[i]);
    }
    */
    long long ans = wayfromS[T] * wayfromS[T] % MOD;
    for(int i=1; i<=N; ++i)
    {
        //not used in shortest path
        if(mindistS[T] != mindistS[i] + mindistT[i]) continue;
        
        if(mindistS[T] == mindistS[i] * 2)
        {
            long long numway = wayfromS[i] * wayfromT[i] % MOD;
            ans -= numway*numway%MOD;
            ans %= MOD; ans += MOD; ans %= MOD;
        }
        for(auto x: conn[i])
        {
            if( mindistS[i] + x.second != mindistS[x.first] ||
                mindistT[x.first] + x.second != mindistT[i]) continue;
            if(mindistS[i] * 2 < mindistS[T] && mindistS[T] < mindistS[x.first]*2)
            {
                long long numway = wayfromS[i] * wayfromT[x.first] % MOD;
                ans -= numway*numway%MOD;
                ans %= MOD; ans += MOD; ans %= MOD;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}














