#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

ll su[MAXN];
ll fac[MAXN];
ll inverse[MAXN];

ll mypow(ll n,ll m)
{
    if(!m)return 1;
    ll ans = mypow(n,m/2);
    ans = ans*ans;
    ans%= MOD;
    if(m%2)ans*=n,ans%=MOD;
    return ans;
}

int main()
{
    ll n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    ll cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;

    fac[0] = 1;

    for(int i=1;i<=n*m;i++)
        fac[i] = (i*fac[i-1])%MOD;

    inverse[n*m] = mypow(fac[n*m],MOD-2);

    for(int i=n*m-1;i>=0;i--)
        inverse[i] = ((i+1)*inverse[i+1])%MOD;

    ll res = 0;

    for(int i=1;i<=max(n,m);i++)
        su[i] = (su[i-1]+(ll)i)%MOD;

    for(int i=1;i<=n;i++){
        cur = (su[i-1]);
        cur = (cur*((m*m)%MOD))%MOD;
        res = (res+cur)%MOD;
    }

    for(int i=1;i<=m;i++){
        cur = (su[i-1]);
        cur = (cur*((n*n)%MOD))%MOD;
        res = (res+cur)%MOD;
    }

    ll ncr = fac[n*m-2];
    ncr = (ncr*inverse[k-2])%MOD;
    ncr = (ncr*inverse[n*m-k])%MOD;

    res = (res*ncr)%MOD;

    cout<<res<<"\n";

    return 0;
}
