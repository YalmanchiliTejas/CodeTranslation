#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
typedef long long ll;

const int MAXL = 5 + 10000;
const int MAXD = 5 + 100;
const int MOD = 1000000000 + 7;

string K;
int memo[MAXL][MAXD][2];
int D;

int dp(int i, int s, bool f) {
    if(i == (int)K.size()) {
        return (s == 0);
    }
    int& ans = memo[i][s][f];
    if(ans == -1) {
        ans = 0;
        if(f) {
            for(char c = '0'; c <= '9'; ++c) {
                ans = (ans + dp(1 + i, (s + (c - '0')) % D, f)) % MOD;
            }
        } else {
            for(char c = '0'; c <= K[i]; ++c) {
                ans = (ans + dp(1 + i, (s + (c - '0')) % D, (c != K[i]))) % MOD;
            }
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> K >> D;
    memset(memo, -1, sizeof memo);
    cout << (dp(0,0,0) - 1 + MOD) % MOD << '\n';
    return 0;
}
