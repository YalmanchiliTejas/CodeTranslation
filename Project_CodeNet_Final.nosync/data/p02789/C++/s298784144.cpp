#include<bits/stdc++.h>
using namespace std;
#define in(s) ll s; cin>>s
#define pr(r) cout<<r<<endl
#define prr(m,n) cout<<m<<" "<<n<<endl
#define prarr(a,i,n) fab(j,i,n) cout<<a[j]<<" "
#define wh(t) ll t; cin>>t; while(t--)
#define sz(u) u.size()
#define all(v) v.begin(),v.end()
#define arr(a,n) ll a[n]; fab(i,0,n) cin>>a[i]
#define showdp(d,n,m) fab(i,0,n){ fab(j,0,m) if(d[i][j]==-1 || d[i][j]>9) cout<<d[i][j]<<" "; else cout<<" "<<d[i][j]<<" "; cout<<endl; }
#define prs(u) cout<<u<<" "
#define fab(i,a,b) for(ll i=a;i<b;i++)
#define fba(i,b,a) for(ll i=b;i>=a;i--)
#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MX 1000000007
#define MAX 10000007
#define endl "\n"
#define ll long long int
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define pl pair<ll,ll>
#define pll pair<ll,pl>
#define vvl vector<vl>
#define mxe(x,n) *max_element(x,x+n)
#define mne(x,n) *min_element(x,x+n)
#define mp make_pair
#define pb push_back
#define fs first
#define sd second
#define fr front()
#define bk back()
#define rr return
#define N 300005
#define inf 1e18+7
 
bool rsort1(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.first > b.first);}
bool rsort2(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.second>b.second);}
bool sort2(const pair<ll,ll> &a,const pair<ll,ll> &b){ return (a.second < b.second);}
 
bool isPrime(ll p)
{
    for(ll i=2;i*i<=p;i++)
        if(p%i==0)
            rr false;
    rr true;
}
 
void sieve(ll n,vl &v)
{
    v.pb(2);
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(ll i=3;i*i<=n;i+=2)
        if(prime[i])
            for(ll j=i;j*i<=n;j+=2)
                prime[j*i]=false;
        
    for(ll i=3;i<=n;i+=2)
        if(prime[i])
            v.pb(i);
}

ll phi(ll n)
{
    ll result=n;
    for(ll p=2;p*p<=n;p++)
    {
        if(n%p==0)
        {
            while(n%p==0)
                n/=p;
            result-=result/p;
        }
    }

    if(n>1)
        result-=result/n;
    return result;
}


int main()
{
	sup;
    
    ll n,m;
    cin>>n>>m;
    if(m>=n) cout<<"Yes";
    else cout<<"No";
	
    return 0;
}