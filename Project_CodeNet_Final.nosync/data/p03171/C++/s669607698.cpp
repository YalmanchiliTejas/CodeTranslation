#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define read()          freopen("fibsubseq.in","r",stdin)
#define write()         freopen("fibsubseq.out","w",stdout)
#define sf(n)           scanf("%d",&n)
#define sfd(n)          scanf("%lf",&n)
#define sl(x)           scanf("%I64d",&x)
#define sfl(n)          scanf("%lld", &n)
#define sfc(n)          scanf(" %c",&n)
#define sful(n)         scanf("%llu",&n)
#define ull             unsigned long long int
#define endll           printf("\n")
#define pf              printf
#define pi              acos(-1.0)
#define eps             1e-10
#define mem(a,b)        memset(a,b,sizeof(a))
#define pb              push_back
#define xx              first
#define yy              second
#define pii             pair<int, int>
#define pll             pair<ll, ll>
#define MP make_pair
#define ll              long long
#define uniq(a)      a.erase(unique(a.begin(), a.end()), a.end())

bool Check(unsigned int  N,int pos){return (bool)(N & (1LL<<pos));}
ll  Set(unsigned int N,int pos){    return N=N | (1LL<<pos);}
#define cnd tree[idx]
#define lnd tree[idx<<1]
#define rnd tree[(idx<<1)+1]
#define lndp (idx<<1),(b),((b+e)>>1)
#define rndp ((idx<<1)+1),(((b+e)>>1)+1),(e)
#define inf 1999999999
#define MX 100005
#define mod  1000000007
#define mod1 1000000009
#define var    int ii,i,j,k,z=0,c=0,t,x,y,l,r,mid,m
//int dx[8]={0,0,1,1,-1,-1,1,-1};  //8 direction
//int dy[8]={1,-1,1,-1,1,-1,0,0};

ll n;
ll a[3005],dp[3005][3005][2];

ll fn(ll x,ll y,ll f)
{
    if(x>y)return 0;
    ll &z=dp[x][y][f];
    if(z!=-1)return z;
    z=0;
    if(f==0)z=max(a[x]+fn(x+1,y,!f),a[y]+fn(x,y-1,!f));
    else z=min(fn(x+1,y,!f),fn(x,y-1,!f));
    return z;
}

int main()
{
    ll var;
    sfl(n);
    for(i=0;i<n;i++)sfl(a[i]),c+=a[i];
    mem(dp,-1);
    z=fn(0,n-1,0);
    cout<<z-(c-z)<<endl;
}
