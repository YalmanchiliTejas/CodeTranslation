
// Problem : F - Knapsack for All Segments
// Contest : AtCoder - AtCoder Beginner Contest 159
// URL : https://atcoder.jp/contests/abc159/tasks/abc159_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define mi map<int,int>
#define ml map<ll,ll>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 998244353
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

int n,s;

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>s;
    vi a(n+1);
    vi dp(s+1);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=s;j>=0;j--){
            int prev = dp[s];
            if((dp[j] || j==0) && j+a[i] <= s){
                dp[j+a[i]] += j==0 ? i+1 : dp[j];
                dp[j+a[i]] %= mod;
            }
            ans += (dp[s]+mod-prev)*(n-i);
            ans %= mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
