#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN][120][3];

int main() {
    #ifdef BLAT
        freopen("input", "r", stdin);
    #endif

    string s;
    cin >> s;

    int d;
    cin >> d;

    s = ' ' + s;
    dp[0][0][1] = 1;
    for(int i = 1; i < s.size(); ++i) {
    	/// Pt Fiecare rest
    	for(int j = 0; j < d; ++j) {
    		/// Pun la obligatea
    		dp[i][(j+s[i]-'0') % d][1] += dp[i-1][j][1];
    		if(dp[i][(j+s[i]-'0') % d][1] >= MOD) dp[i][(j+s[i]-'0') % d][1] -= MOD;

    		/// Pun ca sa ma eliberez
    		for(int k = 0; '0' + k < s[i]; ++k) {
    			dp[i][(j+k)%d][0] += dp[i-1][j][1];
    			if(dp[i][(j+k)%d][0] >= MOD) dp[i][(j+k)%d][0] -= MOD;
    		}


    		/// Sunt deja liber
    		for(int k = 0; k < 10; ++k) {
    			dp[i][(j+k)%d][0] += dp[i-1][j][0];
    			if(dp[i][(j+k)%d][0] >= MOD) dp[i][(j+k)%d][0] -= MOD;
    		}

    	}
    }
    cout << ((dp[s.size() - 1][0][0] + dp[s.size() - 1][0][1] - 1 % MOD) + MOD) % MOD << '\n';
}   	