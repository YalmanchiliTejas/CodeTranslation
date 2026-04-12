/*input
6
4 2 9 7 1 5
*/
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define mpr make_pair
#define MX 1000000007
#define ui unsigned int
#define ll long long
#define ld long double
#define fi first
#define se second
#define testcases int testcases;cin>>testcases;while(testcases--)
#define printvector(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" ";  cout<<endl
#define printarray(v,n)  for(int i=0;i<n;i++) cout<<v[i]<<" ";  cout<<endl
#define inputarray(v,n)  for(int i=0;i<n;i++)cin>>v[i]
#define debug(i) cout<<"debug: "<<i<<endl
#define pr(i) cout<<i<<endl
#define timetaken cerr<<clock()/double(CLOCKS_PER_SEC)<<endl
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


// class graph{
//     unordered_map<int,vector<int>> adjList;
//     int n;
// public:
//     graph(int n){
//         this->n = n;
//     }
//     void addEdge(int a, int b){
//         adjList[a].pb(b);
//         adjList[b].pb(a);
//     }
    
//     ll dfs(int from, vector<vector<ll>>&dp, int col, int parent){
//         if(dp[from][col] != -1) return dp[from][col];
        
//         ll ans = 1;
//         for(auto to: adjList[from]){
//             ll tmp = 1;
//             if(to != parent){
//                 if(col == 1){
//                     tmp = dfs(to, dp, 1-col, from);
//                 } else {
//                     tmp = dfs(to, dp, col, from) + dfs(to, dp, 1-col, from);
//                 }
//             }
//             ans = (ans*tmp)%MX;
//         }
//         return dp[from][col] = ans%MX;
//     }
// };

// double dp[3000][3000];

// double cal(int n, int x, vector<ll> &a){
//     if(x == 0)return 1;
//     if(n == 0) return 0;
    
//     if(dp[n][x] > -0.9) return dp[n][x];
    
//     double ans = a[n-1]*cal(n-1,x-1,a) + (1-a[n-1])*cal(n-1,x,a);
//     return dp[n][x] = ans;
// }

int main() {
    fast_io
    int n;
    cin>>n;
    vector<ll>a(n); inputarray(a,n);
    vector<vector<ll>>dp(n,vector<ll>(n,0));

    ll sum=0;
    for(int i=0;i<n;++i)sum += a[i];
    
    for(int l=1;l<=n;++l){
        for(int i=0;i<=n-l;++i){
            int j = i+l-1;
            if(l == 1)dp[i][j] = a[i];
            else if(l == 2){
                dp[i][j] = max(a[i],a[j]);
            }else{
                dp[i][j] = max(a[i] + min(dp[i+2][j], dp[i+1][j-1]) , a[j] + min(dp[i+1][j-1], dp[i][j-2]));
            }
        }
    }
    ll x = dp[0][n-1];
    ll y = sum - x;
    pr(x-y);
}