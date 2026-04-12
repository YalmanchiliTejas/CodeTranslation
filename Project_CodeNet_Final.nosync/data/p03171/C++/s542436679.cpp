#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 100000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define vll vector<lli>
#define eps 0.000001
#define endl '\n'
#define mo 998244353
 
using namespace std ;
 
#define MAXN 305 

typedef tree<lli,null_type,less<lli>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

lli dp[3000 + 5][3000 + 5];
lli a[3000 + 5];

lli f(lli s, lli e)
{
    if(dp[s][e] != -1) return dp[s][e];
    if(s == e) return dp[s][e] = a[s];

    return dp[s][e] = max(a[s] - f(s+1,e) , a[e] - f(s,e-1));
}


int main()
{
///////////////////////////////////////////

    memset(dp,-1,sizeof(dp));

    lli n;
    cin>>n;

    loopl(i,0,n) cin>>a[i];

    cout<<f(0,n-1)<<endl;

}