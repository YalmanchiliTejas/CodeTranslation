/*Author: Gautam*/
 
 
#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define MOD 1000000007
#define ull unsigned long long int
#define newline cout<<endl
 
 
/* TYPE DEFINITIONS */
typedef     long long int        ll;
typedef     vector<ll>     vi;
typedef     pair<int,int>   pi;
 
 
 
/* MATH */
bool isPrime(ull n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ull i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
 
ll pow(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}

  
//
/* MACROS */
 
#define  all(A)         (A).begin() , (A).end()
#define  arrall(A,n)    (A),((A)+(n))
#define  rall(A)        (A).rbegin() , (A).rend()
#define  sz(A)          (int)(A).size()
#define  pb             push_back
#define  ppb            pop_back
#define  mp             make_pair
#define  ln(X)          (int)(X).length()
#define  square(X)      ((X)*(X))
#define  cube(X)        ((X)*(X)*(X))
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)    for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) 
ll n;
ll arr[3001];
ll bruteForce(ll p1,ll p2)
{
    ll x=0;
    if(p1==p2)
    {
        return arr[p1];
    }
    else
    {
        return max(arr[p1]-bruteForce(p1+1,p2),arr[p2]-bruteForce(p1,p2-1));
    }
}
void solve()
{
    cin>>n;
    forn(i,n)cin>>arr[i];
    //cout<<bruteForce(0,n-1)<<endl;
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(j==i)dp[i][j]=arr[i];
            else dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}  
int main()
{
 
    FastIO;
    ll t=1;
   // cin>>t;
    while(t--)
    {
        solve();
    }
}