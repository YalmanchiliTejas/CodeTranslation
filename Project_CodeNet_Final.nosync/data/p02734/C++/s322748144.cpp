#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353 

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll power(ll a, ll n, ll m)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=(ans*a)%m;
        n>>=1;
        a=(a*a)%m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}

struct tr{
    tr* nxt[26];
    ll c=0;
};

ll n,k;
        
void insert(tr* p, string s)
{
    tr *cur=p;
    repf(i,0,s.length())
    {
        if(!cur->nxt[s[i]-'A']) 
        {
            cur->nxt[s[i]-'A']=new tr();
        }
        cur=cur->nxt[s[i]-'A'];
        cur->c++;
    }
}

ll f(tr *p)
{
    if(!p) return 0;
    ll ans=p->c/k;
    repf(i,0,26)
    {
        if(p->nxt[i]) ans+=f(p->nxt[i]);
    }
    return ans;
}

bool ispalin(string s)
{
    repf(i,0,s.length()/2)
    {
        if(s[i]!=s[s.length()-i-1]) return false;
    }
    return true;
}

ll dp[3001][3001];
ll a[3001];

int main()
{
    IOS;
    ll n,s;
    cin>>n>>s;
    repf(i,1,n+1) cin>>a[i];
    memset(dp,0,sizeof dp);
    repf(i,0,n+1) dp[i][0]=i+1;
    ll ans=0;
    repf(i,1,n+1)
    {
        repf(j,1,s+1)
        {
            dp[i][j]=dp[i-1][j];
            if(j-a[i]>=0)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%MOD;
            }
        }
        ans=(ans+dp[i][s])%MOD;
    }
    cout<<ans<<endl;
    // repf(l,1,n+1)
    // {
    //     repf(r,l,n+1)
    //     {
    //         ans=ans+dp
    //     }
    // }
}   