#include <bits/stdc++.h>
#include <bitset>
#include <chrono>
#include <iomanip>
using namespace std;
 
/////------------------------TYPEDEF--------------------------/////
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
#define prq priority_queue<ll>;
 
/////------------------------CONSTANTS--------------------------/////
ll MOD=1000000007;
#define PI 3.1415926535897932384626433832795
 
/////------------------------GENERAL--------------------------/////
#define forx(i,j,n) for(int i=j;i<n;i++)
#define fory(i,j,n) for(int i=j;i>=n;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false)
#define testcase int t; cin>>t
#define MEM(xx,yy) memset(xx,yy,sizeof(xx))
#define vbs(xx,x) binary_search(all(xx),x)
#define vlb(xx,x) lower_bound(all(xx),x)
#define vub(xx,x) upper_bound(all(xx),x)
 
/////------------------------IO--------------------------/////
#define inpi(xx) scanf("%d",&xx)
#define inpl(xx) scanf("%lld",&xx)
#define inpc(xx) scanf("%c",&xx)
#define inps(xx) scanf("%s",&xx)
#define pri(xx) printf("%d",xx)
#define prl(xx) printf("%lld",xx)
#define prls(xx) printf("%lld ",xx)
#define prle(xx) printf("%lld\n",xx)
#define prc(xx) printf("%c",xx)
#define prs printf(" ");
#define pre printf("\n")
long int idx[100001];
long long int power(long long int x,long long int y,long long int z)
{
    long long int res=1;
    x%=z;
    while(y>0)
    {
        if(y&1)
        res=(res*x)%z;
        x=(x*x)%z;
        y/=2;
    }
    return res;
}

long long int power1(long long int x,long long int y)
{
    long long int res=1;
    while(y>0)
    {
        if(y&1)
        res=(res*x);
        x=(x*x);
        y/=2;
    }
    return res;
}

long int root(long int x)
{
    while(idx[x]!=x)
    x=idx[x];
    return x;
}

void union1(long int x,long int y)
{
    idx[root(x)]=root(y);
}
int n;
long long int a[5000];
long long int dp[3001][3001][2];
long long int fun(int i,int l,int r)
{
    if(l>r)
    return 0;
    if(dp[l][r][i]!=pow(10,15))
    return dp[l][r][i];
    if(i==0)
    dp[l][r][i]=max(fun(1-i,l+1,r)+a[l],fun(1-i,l,r-1)+a[r]);
    else
    dp[l][r][i]=min(fun(1-i,l+1,r)-a[l],fun(1-i,l,r-1)-a[r]);
    return dp[l][r][i];
}
int main() {
       cin>>n;
           for(long int i=0;i<n;i++)
           cin>>a[i];
           for(long int i=0;i<n;i++)
           {
               for(long int j=0;j<n;j++)
               {
                   for(int s=0;s<2;s++)
                   dp[i][j][s]=pow(10,15);
               }
           }
          long long int ans= fun(0,0,n-1);
          cout<<ans;
	return 0;
}