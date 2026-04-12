#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<ll,ll> pii;

int N;
vector<pii> V;
pii D[200010];
pii MAX,MIN;
ll res,res1,res2;
ll ans;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld%lld",&D[i].fi,&D[i].se);
        V.pb(mk(D[i].fi,i));
        V.pb(mk(D[i].se,i));
    }
    sort(V.begin(),V.end());
    MAX = V[N * 2 - 1];
    MIN = V[0];
    res1 = res2 = 0;
    for(int i = 0; i < N; i++)
    {
        res1 = max(res1,abs(MAX.fi - max(D[i].fi,D[i].se)));
        res2 = max(res2,abs(MIN.fi - min(D[i].fi,D[i].se)));
    }
    ans = res1 * res2;
    if(MAX.se != MIN.se)
    {
        res = 1000000000000000000;
        int mem[200010] = {0};
        int l,r;
        int sum = 0;
        l = 0;
        for(int r = 1; r < N * 2 - 1; r++)
        {
            mem[V[r].se]++;
            if(mem[V[r].se] == 1)sum++;
            if(sum == N)
            {
                while(1)
                {
                    l++;
                    mem[V[l].se]--;
                    if(mem[V[l].se] == 0)
                    {
                        sum--;
                        res = min(res,V[r].fi - V[l].fi);
                        break;
                    }
                }
            }
        }
        ans = min(ans,(V[N * 2 - 1].fi - V[0].fi) * res);
    }
    printf("%lld\n",ans);
    return 0;
}
