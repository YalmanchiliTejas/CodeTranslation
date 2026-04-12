#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int i = a;i < b;++i) cout << ary[i] << (b-1 == i ? "]\n" : ", "); } while(0)
#define p_map(map,it) do {cout << "{";for (auto it = map.begin();;++it) {if (it == map.end()) {cout << "}\n";break;}else cout << "" << it->first << "=>" << it->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = n;i >= 0;--i) for (int j = n-i;j >= 0;--j) {
        if (i+j == n) dp[i][j] = 0;
        else if ((i+j)&1) dp[i][j] = min(dp[i+1][j],dp[i][j+1]);
        else dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j+1]+a[n-1-j]);
    }
    ll sum = 0;
    for (int i = 0;i < n;++i) sum += a[i];
    cout << 2*dp[0][0]-sum << endl;
    return 0;
}