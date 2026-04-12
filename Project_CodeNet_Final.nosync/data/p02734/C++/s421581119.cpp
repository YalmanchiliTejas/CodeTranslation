#include<bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x)  (long long)(x).size()
#define sqr(x) (x)*(x)
#define sof sizeof
#define resz resize
#define ins insert
#define lowerB lower_bound
#define upperB upper_bound
#define mkp make_pair
#define mkt make_tuple
#define act(a,v) (get<(long long)a>(v))
#define mod 1000000007
#define mod1 998244353
#define N 200003
#define inf 1e18
#define minf -1e18
#define min3(a,b,c) min(a,min(b,c));
#define max3(a,b,c) max(a,max(b,c));
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define sumall(v) accumulate(all(v),(ll)0)
#define suma accumulate
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION(n) std::cout.unsetf ( std::ios::floatfield );std::cout.precision((ll)n)
#define PI M_PI
#define fi first
#define se second
#define here cout<<"RSSB"<<endl
#define showzero cout<<std::showpoint
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define br "\n"
#define spac " "
#define zero (ll)0
using namespace  std ;
typedef double db;
typedef long long ll ;
typedef vector<int>vi ;
//typedef vector<l>vl ;
typedef vector<ll>vll ;
typedef vector<vector<ll> >vvl ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
typedef vector<pll>vpll;
typedef vector<string>vstr;
typedef vector<tuple<ll,ll,ll> >vtll;
typedef vector<bool>vbool ;
void READ(vll &v, ll n){ll a ;for(ll i=0 ; i<n ; i=i+1){cin>>a ;v.pb(a);}}
void PRINT(vll &v , ll a = 0){for(ll i=a ; i<v.size() ; i=i+1){/*v[i] = max((ll)0,v[i]);*/cout<<v[i]<<"\n" ;}cout<<"\n" ;}
double logy(ll n , ll b){if(b==0){return(-1);}if(n==1){return(0);}return((db)log10(n)/log10(b));}
long long power(long long k , long long n , long long m=mod){long long res = 1;while(n){if(n%2!=0){res = (res*k)%m ;}k = (k*k)%m ;n = n/2 ;}return(res) ;}
double power(double p , ll t){db q = 1;while(t){if(t%2){q*=p;}p*=p;t/=2;}return(q);}
ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
vpll dr;
void call(){dr.pb(mkp(1,0));dr.pb(mkp(-1,0));dr.pb(mkp(0,1));dr.pb(mkp(0,-1));}
ll n,m,k;
bool ok = false;
vll v;
ll dp[3003][3003];
ll solve(ll i , ll j)
{
    if(j>k)
    {
        return(0);
    }
    if(j==k)
    {
        return(n-i+1);
    }
    if(i==n)
    {
        return((j==k));
    }
    if(dp[i][j]!=-1)
    {
        return(dp[i][j]);
    }
    ll ans = (((j==0)*(i+1) + (j!=0)*1)*solve(i+1,j+v[i])%mod1 + solve(i+1,j)%mod1)%mod1;
    dp[i][j] = ans;
    return(ans);
}
int main()
{
    FastIO ;
    PRECISION(20) ;
    ll a,b,c,d,i,j,t,x,y,z,x1,y1,z1,e,f;
    db p,q,r,u,w ;
    char ch,chr ;
    string str,st,str1,str2,str3,str4;
    //ll a1=0,a2=0,b1=0,b2=0,c1=0 ;
    //cin>>str>>str1;
    //call();
    //Constructive is Weak!!
    cin>>n>>k;
    READ(v,n);
    memset(dp,-1,sof(dp));
    a = solve(0,0);
    cout<<a;
}