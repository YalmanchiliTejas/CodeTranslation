#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x, y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x, y, z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define db4(x, y, z, w) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<","<<#w<<"="<<w<<'\n'
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define PR(a, n) {cout<<#a<<"="; for(int __=0;__<n;__++)cout<<a[__]<<' '; cout<<"\n"; }
using namespace std;
using ll =  long long;
#define int ll

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n ;

    vector<int> v(n);
    for (int &i: v)cin >> i;
    vector<vector<int>> dp(n,vector<int> (n));
    for(int i= 0; i< n; ++i){
        dp[i][i] = v[i];
    }
    for(int i= 0; i< n-1; ++i){
        dp[i][i+1] = max(v[i],v[i+1])-min(v[i],v[i+1]);
    }
    int len = 3;
    while(len<=n){
        for(int i= 0; i<n-(len-1); ++i){
            int j = i+len-1;
            int a = dp[i+1][j];
            int b = dp[i][j-1];

            dp[i][j] = max(v[i] - a, v[j] -b);
        }
        ++len;
    }
    cout << dp[0][n-1];
}