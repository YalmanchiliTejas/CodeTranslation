#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N=200005;
#define inf 1e18+8
const int mod=1e9+7;
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define set multiset
#define all(x) begin(x), end(x)
#define vpii vector<pair<int,int> > 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//int dp[N];
int dp1[N];
vi adj[N];
vi adj2[N];
int vis[N];
vi printDivisors(int n) 
{ 
    vi temp;
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                temp.pb(i);
  
            else // Otherwise print both 
                {
                    temp.pb(i);
                    temp.pb(n/i);

                }
        } 
    } 
    return temp;
}
int dp[3001][3001];
int arr[N];
int rec(int first, int last)
{
    if(dp[first][last]!=-1) return dp[first][last];
    if(last<first) return 0;
   // if((last-first)==1) return dp[first][last]=max(arr[first],arr[last]);
    if(first==last) return dp[first][last] = arr[first];
    return dp[first][last]=max(arr[first]+min(rec(first+2,last),rec(first+1,last-1)),arr[last]+min(rec(first,last-2),rec(first+1,last-1)));

}
signed main()
{
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    { 
        cin>>arr[i];
        sum+=arr[i];
    }

    //cout<<rec(1,n);
    cout<<rec(1,n)-(sum-rec(1,n));
    return 0;

}
 
    