#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

void solve()
{
    ll n,x,m;
    cin>>n>>x>>m;
    if (n==1)
    {
        cout<<x;
        return;
    }
    vll val={0};
    vector <int> pos(m);
    pos[x]=1;
    int now=2;
    while (true)
    {
   //     cout<<now<<" "<<n<<'\n';
        val.pb(x);
        x=(x*x)%m;
        if (pos[x]==0)
        {
            pos[x]=now++;
            if (now-1==n)
            {
                ll ans=0;
                for (int i=0;i<m;i++)
                {
                    if (pos[i]==0)
                        continue;
                    ans+=i;
                }
                cout<<ans;
                return;
            }
            continue;
        }
        int pre_cyc=pos[x]-1;
        ll ans=0;
        for (int i=0;i<=pre_cyc;i++)
            ans+=val[i];
        ll sz=now-1-(pre_cyc+1)+1;
        n-=pre_cyc;
        ll sum=0;
        for (int i=pre_cyc+1;i<val.size();i++)
            sum+=val[i];
        ans+=sum*(n/sz);
        n%=sz;
        for (int i=pre_cyc+1;i<pre_cyc+1+n;i++)
            ans+=val[i];
        cout<<ans;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    _t=1;
 //   cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}