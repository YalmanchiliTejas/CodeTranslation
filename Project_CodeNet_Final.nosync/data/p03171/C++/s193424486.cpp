#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> isPair;
using vvll = vector< vector<ll> >;
using vll = vector<ll> ;
#define Pll pair<ll,ll>
#define vpll vector<pll>
#define sll set<ll>
#define mll map<ll,ll>

const ll inf=1e18;
const ll maxs = 1e5;
const ll mod = 1e9+7;

#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define LB lower_bound
#define UB upper_bound
#define line cout<<endl;
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mst(x,a) memset(x,a,sizeof(x))

ll n;
ll a[3003];
ll dp[3003][3003];

ll solve(ll l,ll r,ll sum)
{
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(l==r)
        return dp[l][r] = a[l];
    
    if(l+1==r)  
        return dp[l+1][r] = max(a[l],a[r]);
    
    
    return dp[l][r] = max(sum - solve(l+1,r,sum-a[l]) , sum - solve(l,r-1,sum-a[r]) );
}


int main() 
{
    fastio();
	ll t=1;
    //cin>>t;
    while(t--)
	{
        cin>>n;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {   cin>>a[i];
            sum+=a[i];
        }
        memset(dp,-1,sizeof dp);
        ll first = solve(0,n-1,sum);
        ll second = sum - first;
        cout<<first-second;
    }
	
	return 0;
}