#include<bits/stdc++.h>
using namespace std;

/* // Ordered Set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
*/

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)
// int ncr(int n,int r) {return (fact[n]*modInv(fact[r]))%mod*modInv(fact[n-r])%mod;}
// int modInv(int i) {return binExp(i,mod-2);}

int dp[3001][3001];

signed main()
{
    fast

    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif

    // test
    {
        int n;
        cin>>n;

        f1(i,0,n)f1(j,0,n) dp[i][j] = 0;

        int a[n];
        f0(i,0,n) cin>>a[i];
        f0(i,0,n) dp[i][i] = a[i];

        f3(i,n-1,0)
        {
            f0(j,i+1,n)
            {
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);

            }
        }
        cout<<dp[0][n-1];
    }
}