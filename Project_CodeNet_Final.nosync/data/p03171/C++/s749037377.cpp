#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int long long
#define pb push_back 
#define ins insert
#define rs resize
#define br break;
#define cont continue;
#define vi vector<ll>
#define vll vector<long long>
#define si set<ll>
#define sll set<long long>
#define pii pair<ll,ll>
#define pll pair<long long, long long>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vec vector
#define cend cout<<endl;
#define sc second
#define fr first
#define retz return 0;
#define ll_MAX (ll)(1e9*1e9)
#define ll_MIN (ll)(-1e9*1e9)
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b)  for(int i=a; i<=b; i++)
#define repd(i,a,b) for(int i=a; i>=b; i--)
#define ps(arr, n) for(int i=1; i<n; i++)arr[i]+=arr[i-1];
#define inp(arr, n)for(int i=0; i<n; i++)cin>>arr[i];
#define out(arr, n)for(int i=0; i<n; i++)cout<<arr[i];
#define inp1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define out1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define loop(q) for(auto it:q)
#define loop1(q) for(auto&it:q)
#define db1 cout << "*" << endl
#define db2 cout << "YES" << endl
using namespace std;
using namespace __gnu_pbds; 
#define oset(X) tree<X,null_type,less<X>, rb_tree_tag, tree_order_statistics_node_update> 
#define roset(X) tree<X,null_type,greater<X>, rb_tree_tag, tree_order_statistics_node_update>  
#define okey order_of_key //lower_bound_set
#define ofind find_by_order
#define cyes cout << "Yes" << endl;
#define cno cout << "No" << endl;
#define mod 1000000007
#define mod2 998244353
#define INT_MAX1 900000000
//////////////////////////////////////////////////////////////////////////////////////////////

int n;
int arr[3001];
int dp[3001][3001][2];
bool v[3001][3001][2];

int s1(int i, int j, bool turn)
{
    if(i==j)
        if(turn)
            return -1*arr[i];
        else
            return arr[i];
    if(v[i][j][turn])
        return dp[i][j][turn];
    v[i][j][turn] = 1;
    if(!turn)
    {
        dp[i][j][turn] = max(arr[i]+s1(i+1,j,!turn),arr[j]+s1(i,j-1,!turn));
    }
    else
    {
        dp[i][j][turn] = min(-1*arr[i]+s1(i+1,j,!turn),-1*arr[j]+s1(i,j-1,!turn));
    }

    return dp[i][j][turn];

}

void solve()
{
    cin >> n;
    inp(arr,n);
    cout << s1(0,n-1,0);
}

 
int32_t main()
{
    speed;
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}