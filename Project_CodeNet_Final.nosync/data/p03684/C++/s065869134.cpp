#include<bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<ll,pair<int,ll> > plpil;

int N;
ll ans = 0;
bool used[100010] = {0};
vector<pli> X,Y;
vector<pli> E[100020];

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        X.pb(mp(a,i));Y.pb(mp(b,i));
    }
    sort(all(X));sort(all(Y));
    for(int i = 0; i < X.size() - 1; i++)
    {
        ll xl = X[i + 1].fi - X[i].fi,yl = Y[i + 1].fi - Y[i].fi;
        E[X[i].se].pb(mp(xl,X[i + 1].se));E[X[i + 1].se].pb(mp(xl,X[i].se));
        E[Y[i].se].pb(mp(yl,Y[i + 1].se));E[Y[i + 1].se].pb(mp(yl,Y[i].se));
    }
    priority_queue<pli, vector<pli>, greater<pli> > Q;
    Q.push(mp(0,0));
    while(Q.size())
    {
        pli now = Q.top();
        Q.pop();
        if(used[now.se])continue;
        used[now.se] = true;
        ans += now.fi;
        for(int i = 0; i < E[now.se].size(); i++)
        {
            Q.push(mp(E[now.se][i].fi,E[now.se][i].se));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
