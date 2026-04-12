#include<bits/stdc++.h>
using namespace std;

#define se second
#define fi first
#define mk(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll > lll;

int N,M;
int S,T;
vector<pll> G[100010];
priority_queue<lll,vector<lll>,greater<lll> > Q;
pll DS[100010],DT[100010];
ll mod = 1000000007;
lll edge[200010];

ll pow_mod(ll a,ll b)
{
    if(b == 0)return 1LL;
    ll res = pow_mod(a * a % mod,b / 2);
    if(b & 1)res = res * a % mod;
    return res;
}

int main()
{
    scanf("%d%d",&N,&M);
    scanf("%d%d",&S,&T);
    for(int i = 0; i < M; i++)
    {
        ll a,b;
        ll c;
        scanf("%lld%lld%lld",&a,&b,&c);
        G[a].push_back(mk(c,b));
        G[b].push_back(mk(c,a));
        edge[i] = mk(c,mk(a,b));
    }

    for(int i = 0; i <= N; i++)DS[i] = mk(-1,0);
    DS[0] = mk(0,1LL);
    Q.push(mk(0,mk(S,0)));
    while(Q.size())
    {
        lll now = Q.top();
        Q.pop();
        if(DS[now.se.fi].fi != -1)
        {
            if(now.fi == DS[now.se.fi].fi)DS[now.se.fi].se += DS[now.se.se].se;
            DS[now.se.fi].se %= mod;
            continue;
        }
        DS[now.se.fi] = mk(now.fi,DS[now.se.se].se);
        for(int i = 0; i < G[now.se.fi].size(); i++)Q.push(mk(now.fi + G[now.se.fi][i].fi,mk(G[now.se.fi][i].se,now.se.fi)));
    }

    for(int i = 0; i <= N; i++)DT[i] = mk(-1,0);
    DT[0] = mk(0,1LL);
    Q.push(mk(0,mk(T,0)));
    while(Q.size())
    {
        lll now = Q.top();
        Q.pop();
        if(DT[now.se.fi].fi != -1)
        {
            if(now.fi == DT[now.se.fi].fi)DT[now.se.fi].se += DT[now.se.se].se;
            DT[now.se.fi].se %= mod;
            continue;
        }
        DT[now.se.fi] = mk(now.fi,DT[now.se.se].se);
        for(int i = 0; i < G[now.se.fi].size(); i++)Q.push(mk(now.fi + G[now.se.fi][i].fi,mk(G[now.se.fi][i].se,now.se.fi)));
    }

    ll ans = pow_mod(DT[S].se,2LL);
    for(int i = 1; i <= N; i++)
    {
        if(DS[i].fi == DT[i].fi)ans -= pow_mod(DS[i].se * DT[i].se % mod,2LL);
        ans = (ans + mod) % mod;
    }
    for(int i = 0; i < M; i++)
    {
        lll now = edge[i];
        if(DS[now.se.fi].fi > DS[now.se.se].fi)swap(now.se.fi,now.se.se);
        if(DS[now.se.fi].fi + DT[now.se.se].fi + now.fi == DS[T].fi && 2LL * DS[now.se.fi].fi < DS[T].fi && 2LL * DT[now.se.se].fi < DS[T].fi)ans -= pow_mod(DS[now.se.fi].se * DT[now.se.se].se % mod,2LL);
        ans = (ans + mod) % mod;
    }
    printf("%lld\n",ans);
    return 0;
}
