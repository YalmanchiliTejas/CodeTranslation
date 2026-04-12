
// Problem : E - Almost Everywhere Zero
// Contest : AtCoder - AtCoder Beginner Contest 154
// URL : https://atcoder.jp/contests/abc154/tasks/abc154_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Macros

#define ll long long
#define db long double
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define inf 1e10
#define PI acos(-1.0)
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 102

//Solution

string s;
int dp[102][2][5],k;

void solve(){
    cin>>s>>k;
    dp[0][0][0] = 1;
    for(int i=0;i<sz(s);i++){
        for(int j=0;j<2;j++){
            for(int l=0;l<=k;l++){
                int limit = (j ? 9 : (s[i]-'0'));
                for(int dig=0;dig<=limit;dig++){
                    dp[i+1][j||dig<limit][l+(dig!=0)] += dp[i][j][l];
                }
            }
        }
    }
    cout<<dp[sz(s)][0][k]+dp[sz(s)][1][k]<<endl;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tests;
    //cin>>tests;
    tests = 1;
    while(tests--){
        solve();
    }
    return 0;
}