#include <bits/stdc++.h>
#define maxn 200005
#define mod 1000000007
using namespace std;

/// DP Digit Template

vector <int> digit;
long long dp[10005][105][3], k;

void getdigit(string x){
    digit.clear();
    for(int i = x.size() - 1; i >= 0; i--)
        digit.push_back(x[i] - 48);
}

long long getsum(int id, int sum, int tight){
    if(id == -1)
        return (sum == 0) ? 1 : 0;
    if(dp[id][sum][tight] > -1 && tight == 0)
        return (dp[id][sum][tight]) % mod;
    long long res = 0, k1 = (tight == 0) ? 9 : digit[id];
    for(int i = 0; i <= k1; i++){
        int newt = (i == digit[id]) ? tight : 0;
        res = (res + getsum(id - 1, (sum + i) % k, newt)) % mod;
    }
    if(tight == 0)
        dp[id][sum][tight] = res % mod;
    return res % mod;
}

long long query(string l, string r){
    memset(dp, -1, sizeof(dp));
    getdigit(l);
    long long a = getsum(digit.size() - 1, 0, 1);
    getdigit(r);
    long long b = getsum(digit.size() - 1, 0, 1);
    return (b - a + mod) % mod;
}

/// End of template

string r;
main(){
    cin >> r >> k;
    cout << query("0", r);
}
