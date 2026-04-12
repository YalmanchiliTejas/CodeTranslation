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

ll n;
ll a[maxs];
isPair dp[3003][3003];

void solve()
{
    for(ll i=0;i<n;i++)
        dp[i][i] = mp(a[i],0);
    
    for(ll j=1;j<n;j++)
    {
        ll k = j;
        for(ll i=0;i<n-j;i++)
        {
            dp[i][k].ff = max( a[i] + dp[i+1][k].ss , a[k] + dp[i][k-1].ss );
            if(dp[i][k].ff==a[i]+dp[i+1][k].ss)
                dp[i][k].ss = dp[i+1][k].ff;
            else
                dp[i][k].ss = dp[i][k-1].ff;
            k++;
        }
    }
    
    /*for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cout<<"("<<dp[i][j].ff<<", "<<dp[i][j].ss<<")\t";
        line;    
    }*/
    cout<<dp[0][n-1].ff - dp[0][n-1].ss;
        
}

int main() {
    fastio();
    ll t=1;
    //cin>>t;
    while(t--){
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>a[i];
        solve();
    }
	return 0;
}