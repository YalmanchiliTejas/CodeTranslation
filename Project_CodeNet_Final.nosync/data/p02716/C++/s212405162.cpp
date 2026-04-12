
// Problem : F - Select Half
// Contest : AtCoder - AtCoder Beginner Contest 162
// URL : https://atcoder.jp/contests/abc162/tasks/abc162_f
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
#define mod 1000000007
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

int n;
int a[200005];

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vi pre(n+1), dp(n+1);
    pre[1] = a[1];
    for(int i=3;i<=n;i+=2) pre[i] = pre[i-2]+a[i];
    for(int i=2;i<=n;i++){
        if(i%2) dp[i] = max(dp[i-1],dp[i-2]+a[i]);
        else {
            dp[i] = a[i]+dp[i-2];
            dp[i] = max(dp[i],pre[i-1]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
