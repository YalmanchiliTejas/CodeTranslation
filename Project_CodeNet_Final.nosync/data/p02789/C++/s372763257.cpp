#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
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
#define N 300003  //N idhar hai
#define inf 1e18
#define minf -1e18
#define min3(a,b,c) min(a,min(b,c));
#define max3(a,b,c) max(a,max(b,c));
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION(n) std::cout.unsetf ( std::ios::floatfield );std::cout.precision((ll)n)
#define getsm(v) accumulate(all(v),(ll)0)
#define getmx(v) max_element(all(v))
#define getmn(v) min_element(all(v))
#define wr1(v) cout<<v<<endl
#define wr2(a,b) cout<<a<<" "<<b<<endl
#define wr3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define call(dr) dr.pb(mkp(1,0));dr.pb(mkp(-1,0));dr.pb(mkp(0,1));dr.pb(mkp(0,-1))
#define fill(dp,a,b) for(int i=0;i<a;i++)for(int j=0;j<b;j++)dp[i][j]=-1;
#define PI M_PI
#define fi first
#define se second
#define here cout<<"RSSB"<<endl
#define showzero cout<<std::showpoint
#define bitcount( x ) __builtin_popcountll( x )
#define ls(i) (1ll<<(i))
#define rs(i) ((i)>>1)
#define br "\n"
//#define sp " "
using namespace __gnu_pbds; //required
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
typedef vector<bool>vbool ;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void READ(vll &v, ll n){ll a ;for(ll i=0 ; i<n ; i=i+1){cin>>a ;v.pb(a);}}
void PRINT(vll &v , ll a = 0){for(ll i=a ; i<v.size() ; i=i+1){/*v[i] = max((ll)0,v[i]);*/cout<<v[i]<<" " ;}cout<<"\n" ;}
double logy(ll n , ll b){if(b==0){return(-1);}if(n==1){return(0);}return((db)log10(n)/log10(b));}
long long power(long long k , long long n , long long m=mod){long long res = 1;while(n){if(n%2!=0){res = (res*k)%m ;}k = (k*k)%m ;n = n/2 ;}return(res) ;}
double power(double k , long long n ){double res = 1;while(n){if(n%2!=0){res = (res*k) ;}k = (k*k) ;n = n/2 ;}return(res) ;}
ll sign(ll i){if(i==0){return(0);}if(i>0){return(1);}return(-1);}
double distance(pll a , pll b){return((db)(sqrt( sqr(a.fi-b.fi) + sqr(a.se-b.se))));}
double distance(pair<ll,pll> a , pair<ll,pll> b){return((db)(sqrt( sqr(a.fi-b.fi) + sqr(a.se.fi-b.se.fi) + sqr(a.se.se - b.se.se))));}
ll lis(vll v){ll d = sz(v);vll dis(d+1,inf);for(ll i = 0 ; i<d ; i++){*lowerB(all(dis),v[i]) = v[i];}for(ll i=0 ; i<d+1 ; i++){if(dis[i]==inf){return(i);}}return(1);}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }//for strictly increasing use lower bound(in function lis) otherwhise use upper bound
#define lcm(a,b) ((a/gcd(a,b))*b)
const ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
vpll dr;
ll n,m,k,h,a1,a2,t;
db prob;
string str;
bool ok = true;
int main()
{
    FastIO ;
    PRECISION(10) ;
    ll a,b,c,d,i,j,x,y,z;//,x1,y1,z1,e,f;
    ll p,q,r,w;
    char ch,chr ;
    string str1,str2,str3,str4;
    //ll a1=0,a2=0,b1=0,b2=0,c1=0 ;
    //cin>>str>>str1;
    //Listen to Zero(Imagine Dragons!!)
    //Stay Motivated!!
    //Never use i for two or more nested loops!!
    //Range Query + Constructive + DSU +  Graph Theory + Math + Number Theory + DP + Bitmasks + Data Structures + Strings + Geometry + Brute Force + Greedy + Implementation
    //Binary and Ternary Search 
    //In a comparator function comp(pll a , pll b) if comp returns true then a comes before b otherwise b comes berfore a
    //For Longest Common Palindromic Subsequence find the Longest Common subsequence between Original Array and Reverse of the original array 
    //Fuck Excuses!!Focus on how to get better
    //First Think then code
    //memset(dp,-1,sof(dp));
    //call(dr);
    //1920
    cin>>n>>m;
    if(n==m)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}