#include <bits/stdc++.h>

using namespace std;

#define S second
#define F first

typedef long long ll;

const int maxn = 2e5+10;
const int mod = 1e9+7;

int n;
ll seg[4*maxn], la[4*maxn];

void shift(int v)
{
    seg[v] += la[v];
    if(2*v+1 < 4*maxn)
    {
        la[2*v] += la[v];
        la[2*v+1] += la[v];
    }
    la[v] = 0;
}

void up(int l, int r, ll val, int v = 1, int tl = 0, int tr = n-1)
{
    shift(v);
    if(l > r) return;
    if(tl == l && tr == r)
    {
        la[v] += val;
        shift(v);
        return;
    }

    int tm = (tl + tr) >> 1;
    up(l, min(tm,r), val, 2*v, tl, tm);
    up(max(tm+1,l), r, val, 2*v+1, tm+1, tr);

    seg[v] = max(seg[2*v], seg[2*v+1]);
}

ll qu(int l, int r, int v = 1, int tl = 0, int tr = n-1)
{
    shift(v);
    if(l > r) return 0;
    if(tl == l &&  tr == r) return seg[v];

    int tm = (tl + tr) >> 1;
    return max(qu(l, min(tm,r), 2*v, tl, tm),
               qu(max(tm+1,l), r, 2*v+1, tm+1, tr));
}

int m;
ll dp[maxn];
ll s[maxn];
vector<pair<int,ll>> L[maxn];

int main()
{
    cin>> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int l, r, val; cin>> l >> r >> val;
        L[r].push_back({l,val});
    }

    for(int i = 1; i <= n; i++)
    {
        for(auto l : L[i])
            up(l.F-1, i-1, l.S);
        dp[i] = qu(0,i-1);
        dp[i] = max(dp[i],0ll);
        if(i == n)
            return cout<< dp[i], 0;
        up(i,i,dp[i]);
    }
}



