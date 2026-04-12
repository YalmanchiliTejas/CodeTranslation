
// Problem : S - Digit Sum
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_s
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
#define N 10005

//Solution

int n;
string s;
int d;
int dp[N][102][2];

int f(int i, int cur, int p){
    if(i == n){
        if(cur == 0) return 1;
        return 0;
    }
    int &ret = dp[i][cur][p];
    if(~ret) return ret;
    int cap = (p == 1 ? (s[i]-'0') : 9);
    ret = 0;
    for(int k=0;k<=cap;k++){
        if(p == 1 && k == cap) (ret += f(i+1,(cur+k)%d,1)) %= mod;
        else (ret += f(i+1,(cur+k)%d,0)) %= mod;
    }
    return ret;
}

void solve(){
    cin>>s>>d;
    n = sz(s);
    memset(dp,-1,sizeof(dp));
    cout<<(f(0,0,1)-1+mod)%mod<<'\n';
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