/* Suryansh Kumar */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define MOD 1000000007
#define oo 1000000000000000000
#define forr(i,n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define pb push_back
#define vect(x) vector<x>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
using namespace __gnu_pbds; 
using namespace std;

ll valueOfIndex(ordered_set&s , ll i){ return *(s.find_by_order(i)); }
ll indexOfValue(ordered_set&s , ll x){ return s.order_of_key(x); }

ll add(ll a, ll b,ll p=MOD) { a%=p; b%=p; return (a+b + p)%p;}
ll mul(ll a, ll b,ll p=MOD) { a%=p; b%=p; return (a*b + p)%p;}

ll power(ll x,ll n,ll p=MOD){ if(x==0) return 0; if(n==0 || x==1) return 1LL;
    ll r = (power(x,n/2,p))%p; if(n&1) return mul(mul(r,r,p) , x,p); else return mul(r,r,p);
}

ll dp[3010][3010][2];
ll a[3010];
ll n;
    
ll get(ll s, ll e, ll turn)
{
    if(s>e) return 0;
    
    if(dp[s][e][turn]!=-1) return dp[s][e][turn];
    
    if(turn==0)
        return dp[s][e][turn] = max( a[e] + get(s,e-1,1) , a[s] + get(s+1,e,1));
    else 
        return dp[s][e][turn] = min( get(s,e-1,0) - a[e] ,  get(s+1,e,0) - a[s] );
}
    
    
void solve()
{
    
    cin >> n;
    forr(i,n) cin >> a[i];
    
    memset(dp,-1,sizeof(dp));
    cout << get(0,n-1 ,0) << "\n";

    
    return;
}


int main()
{
    
    
    fastio
    
    ll tc=1;
  //  read(tc);
    while(tc--)
    {
        solve();
    }
    
    return 0;
}