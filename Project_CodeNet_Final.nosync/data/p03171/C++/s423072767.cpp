#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_ll.hpp>
//using boost::multiprecision::cpp_ll; // use cpp_ll as data type for large numbers 
using namespace std;

#define int ll
#define ll long long
#define pb push_back
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<long long>
#define log2(X) (63ll - __builtin_clzll(X))
#define test ll t; cin>>t; while(t--)
#define modInv(n) po(n,mod-2)%mod
#define ncr(n,r) (((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod

ll po(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res%mod;
}
int n;
int arr[3005];
int dp[3005][3005];

int go(int i, int j)
{
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(i==j) dp[i][j]=arr[i];
    
    else dp[i][j]=max(arr[i]-go(i+1,j),arr[j]-go(i,j-1));
    
    return dp[i][j];
}

signed main() 
{
    fast()
    //test
    {
      cin>>n;
      for(int i=1; i<=n; i++) cin>>arr[i];
      
      memset(dp,-1,sizeof(dp));
      
      cout<<go(1,n)<<"\n";
    }   
}
