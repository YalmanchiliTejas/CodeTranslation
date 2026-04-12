#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define read()          freopen("in.txt","r",stdin)
#define write()         freopen("out.txt","w",stdout)
#define sf(n)           scanf("%d",&n)
#define sfd(n)          scanf("%lf",&n)
#define sl(x)           scanf("%I64d",&x)
#define sfl(n)          scanf("%lld", &n)
#define sfc(n)          scanf(" %c",&n)
#define sful(n)         scanf("%llu",&n)
#define ull             unsigned long long
#define endll           pf("\n")
#define pf              printf
#define PI              acos(-1.0)
#define eps             1e-12
#define mem(a,b)        memset(a,b,sizeof(a))
#define pb              push_back
#define xx              first
#define yy              second
#define pii             pair<int, int>
#define pll             pair<ll, ll>
#define MP make_pair
#define ll              long long
#define uniq(a)      a.erase(unique(a.begin(), a.end()), a.end())
#define cnd tree[idx]
#define lnd tree[idx<<1]
#define rnd tree[(idx<<1)+1]
#define lndp (idx<<1),(b),((b+e)>>1)
#define rndp ((idx<<1)+1),(((b+e)>>1)+1),(e)
#define inf 1999999999
#define MOD  998244353
#define mod1 1000000009
#define var    int n,m,i,j,c=0,t,l,r,mid,z=0,k,x,y
#define aloc(n,t) ((t*)malloc((n)*sizeof(t)))

int dx[8]={0,0,1,1,-1,-1,1,-1};  //8 direction
int dy[8]={1,-1,1,-1,1,-1,0,0};
//int dx[4]={1,-1,0,0};  //4 direction
//int dy[4]={0,0,1,-1};

ll n,m,a[200005],b[200005],x;
vector<ll> v;
int main()
{
    sfl(n);sfl(x);sfl(m);
    a[x] = 1;
    b[x] = 1;
    ll c = x;
    v.pb(x);
    ll l = n+1,j=0;
    for(int i=2;i<=n;i++)
    {
        c*=c;c%=m;
        if(a[c])
        {
            i--;
            j = i;
            l = a[c]-1;
            break;
        }
        b[c]++;
        a[c] = i;
        v.pb(c);
    }
    if(l!=n+1)
    {
       // cout<<j<<" "<<l<<endl;
        n-=j;
        ll sz = v.size();
        ll extra = n%(sz-l);
        for(int i=l;i<sz;i++)
        {
            if(extra>0)
            {
                extra--;
                b[v[i]]++;
            }
            b[v[i]]+=(n/(sz-l));
        }
    }
    ll ans =0;
    for(int i=0;i<m;i++)
    {
        ans += (b[i]*i);
    }
    cout<<ans<<endl;
}
