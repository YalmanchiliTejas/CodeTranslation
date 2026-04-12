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
const ll maxs = 100005;
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

ll a[maxs];
ll n;
ll dp[3002][3002]; // just reduce size before run;

ll solve(ll l,ll r)
{
    if(dp[l][r]!=-1) 
        return dp[l][r];
  	if(l==r+1)
      	return max(a[l],a[r]);
  
    if(l==r)
    {
        return dp[l][r] = a[l];
    }
    ll left = a[l] - solve(l+1,r);
    ll right = a[r] - solve(l,r-1);
    
    return dp[l][r] = max(left,right);
}

int main(){
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
	cout<<solve(0,n-1);
	//cout<<dp[0][n-1];
	return 0;
}