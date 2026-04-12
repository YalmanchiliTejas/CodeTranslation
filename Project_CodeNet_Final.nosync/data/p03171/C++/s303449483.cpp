#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define mset(a,i) memset(a,i,sizeof(a))
#define mii map<int,int>  
#define pii pair<int,int>
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds1;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 3e5+5;
int dp[3005][3005][2];

void solve(){
    int n,sum = 0;
    cin>>n;
    vi a(n);
    loop(i,0,n){
        cin>>a[i];
        sum += a[i];
    }
    mset(dp,0);
    loop(i,0,n){
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for(int rminusl=1;rminusl<n;rminusl++){
        for(int l=0;l<n;l++){
            int r = l+rminusl;
            if(r>=n){
                break;
            }
            dp[l][r][0] = max(a[l]+dp[l+1][r][1],a[r]+dp[l][r-1][1]);
            dp[l][r][1] = min(dp[l+1][r][0],dp[l][r-1][0]);
        }
    }
    int x = dp[0][n-1][0];
    int ans = 2*x-sum;
    cout<<ans<<endl;
}

int32_t main(){
    get_it_done(); 
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
