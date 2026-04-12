#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<algorithm>
#define ll long long
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 1000004
#define INF 1e9+7

using namespace std;

ll n,h[N],mod = 1e9+7;
ll dp1[N],dp2[N]; // dp1[i] = solution for which row i is either RBRBR... or BRBRB.... dp2[i] = full solution
vector < vector < ll > > graph(N);
pair < ll,ll > seg[4*N];
ll w[N];

ll expo(ll vasi,ll ek)
{
    if(ek == 1)
        return vasi;

    if(ek == 0)
        return 1;

    ll x = expo(vasi,ek/2);

    x =  (x*x)%mod;

    if(ek%2==1)
        x = (x*vasi)%mod;

    return x;
}

void build(ll low,ll high,ll pos)
{
    if(low == high)
    {
        seg[pos].first = h[low];
        seg[pos].second = low;

        return;
    }

    ll mid = (low + high)/2;

    build(low,mid,pos*2+1);
    build(mid+1,high,pos*2+2);

    if(seg[pos*2+1].first <= seg[pos*2+2].first)
    {
        seg[pos] = seg[pos*2+1];
    }
    else
    {
        seg[pos] = seg[pos*2+2];
    }

    return;
}

pair < ll,ll > query(ll low,ll high,ll pos,ll slow,ll shigh)
{
    if(low >= slow && high <= shigh)
    {
        return seg[pos];
    }
    if(low > shigh || high < slow)
    {
        return make_pair(INF,-1);
    }

    ll mid = (low + high) / 2;

    pair < ll,ll > q1 = query(low,mid,pos*2+1,slow,shigh);
    pair < ll,ll > q2 = query(mid+1,high,pos*2+2,slow,shigh);

    if(q1.first <= q2.first)
    {
        return q1;
    }

    return q2;
}

void decompose(ll low,ll high,ll parent,ll prevval)
{
    if(low == high)
    {
        w[low] = 1;
        graph[parent].push_back(low);
        return;
    }

//    cout << low << " " << high << " "<< parent << " "<<prevval<<endl;

    pair < ll,ll > cur = query(0,n-1,0,low,high);

    if(cur.first == prevval)
    {
        w[parent]++;

        if(low != cur.second)
            decompose(low,cur.second-1,parent,cur.first);

        if(high != cur.second)
            decompose(cur.second+1,high,parent,cur.first);

        return;
    }

    w[cur.second] = 1;
    graph[parent].push_back(cur.second);

    if(low != cur.second)
        decompose(low,cur.second-1,cur.second,cur.first);

    if(high != cur.second)
        decompose(cur.second+1,high,cur.second,cur.first);

    return;
}

void dfs(ll cur)
{
    cout << cur << ": " << "in\n";

    rep(i,0,graph[cur].size())
    {
        dfs(graph[cur][i]);
    }
    cout << cur << ": " << "out\n";

    return;
}

ll calc1(ll cur,ll removed)
{
    if(dp1[cur])
    {
        return dp1[cur];
    }

    ll res = expo(2,h[cur] - removed);

    rep(i,0,graph[cur].size())
    {
        res = (res*calc1(graph[cur][i],h[cur]))%mod;
    }

    return dp1[cur] = res;
}

ll calc2(ll cur,ll removed)
{
    if(dp2[cur])
    {
        return dp2[cur];
    }

   // cout << cur << " " << w[cur] << endl;

    ll res = expo(2,w[cur]);

    rep(i,0,graph[cur].size())
    {
        res = (res*(calc1(graph[cur][i],h[cur]) + calc2(graph[cur][i],h[cur])))%mod;
    }

    ll res1 = (expo(2,h[cur] - removed) - 2 + mod)%mod;

    rep(i,0,graph[cur].size())
    {
        res1 = (res1*calc1(graph[cur][i],h[cur]))%mod;
    }

    return dp2[cur] = (res+res1)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    rep(i,0,n)
    {
        cin >> h[i];
    }

    build(0,n-1,0);

    decompose(0,n-1,n,-1);

    cout << calc2(n,0) << endl;

    return 0;
}

