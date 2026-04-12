#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mat vector<vi>
using namespace std;
const int mod = 1e9+7;
const int N = 1e4+5;
int dp[N][102];
main() {
    ios::sync_with_stdio(0);
    string k;
    int d;
    cin >> k>>d;
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int rem = 0; rem < d; rem++)
        for (int dig = 0; dig <= 9; dig++)
            (dp[i][(rem+dig)%d] += dp[i-1][rem])%=mod;
    }
    int g = 0;
    int ans = 0;
    for (int i = 0; i < k.size(); i++) {
        int rem = (int)k.size() - (i+1);
        int e = (k[i] - '0');
        for (int q = 0; q < e; q++) {
        (ans += dp[rem][((d - g - q)%d+d)%d])%=mod;
        if (q ==0 && i == 0) ans--;
        if(ans == -1) ans+=mod;
        }
        g += (k[i] - '0');
            g%=d;
    }
    if (g % d == 0) (ans = (ans+1)%mod);
    cout << ans;

}
