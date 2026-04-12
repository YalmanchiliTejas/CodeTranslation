#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define inrep int t;cin>>t; while(t--)
#define pb emplace_back
using namespace std;
using namespace __gnu_pbds; 


typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll; 
typedef vector<string> vs;
typedef long double ld;
const ll MOD = 1e9+7;
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {

    for ( unsigned   i=0; i<v.size(); i++ )
        in>>v[i];
    return in;
}

ll power(ll x, ll y,ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2,m)%m; 
    p = (p * p)%m; 
  
    return (y%2 == 0)? p : (x * p)%m ; 
} 

ll modInverse(ll a, ll m) 
{ 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
    return power(a, m-2,m); 
} 
  
// To compute x^y under modulo m 
ll dp[3001][3001][2];
ll a[3001];
ll calc(int i,int j,int k)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(k==0)
    {
        dp[i][j][k] = max(a[i]+calc(i+1,j,1-k),a[j]+calc(i,j-1,1-k));
    }
    else
    {
        dp[i][j][k] = min(calc(i+1,j,1-k)-a[i],calc(i,j-1,1-k)-a[j]);
    }
    return dp[i][j][k];
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mset(dp,-1);
    cout<<calc(0,n-1,0);
    
    
    return 0;
}