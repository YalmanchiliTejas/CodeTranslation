#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+10, maxs = 110, mod = 1e9+7;

vector<int> digit;

int n, d, dp[maxn][maxs][2];

void add_self(int &a, int b){
    a += b;
    if(a>=mod){
        a -= mod;
    }
}

int solve(int pos, int sum, bool flag){
    if(dp[pos][sum][flag] != -1) return dp[pos][sum][flag];
    if(pos == n) return (sum%d == 0 ? 1 : 0);

    if(flag){
        int tot = 0;

        for(int i=0; i<=digit[pos]; i++){
            add_self(tot, solve(pos+1, (sum+i)%d, (i == digit[pos])));
        }

        return dp[pos][sum][flag] = tot;
    }
    else{
        int tot = 0;

        for(int i=0; i<=9; i++){
            add_self(tot, solve(pos+1, (sum+i)%d, 0));
        }

        return dp[pos][sum][flag] = tot;
    }
}

int calc(string k){
    n = (int)k.size();

    digit.resize(n);

    for(int i=0; i<n; i++) digit[i] = k[i] - '0';

    memset(dp, -1, sizeof dp);

    int ans = solve(0, 0, 1) - 1;

    if(ans == -1) ans += mod;

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string k;

    cin >> k >> d;

    cout << calc(k) << endl;

    return 0;
}
