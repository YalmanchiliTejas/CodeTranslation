#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
string str;
int dp[100010][110][2], d;
int f(int pos, int sum, int flag) {
    if(pos == (int)str.size()) return sum == 0;
    int &ans = dp[pos][sum][flag];
    if(ans == -1){
        int lim = str[pos] - '0';
        ans = 0;
        for(int i = 0; i <= 9; i++) {
            if(flag || i < lim) ans += f(pos + 1, (sum + i + d) % d, 1);
            else if(i == lim) ans += f(pos + 1, (sum + i + d) % d, 0);
            ans %= MOD;
        }
    }
    return ans;
}
int main(){
    fast;
    memset(dp, -1, sizeof dp);
    cin >> str >> d;
    cout << (f(0,0,0) - 1 + MOD) % MOD << "\n";
    return 0;
    return 0;
}
