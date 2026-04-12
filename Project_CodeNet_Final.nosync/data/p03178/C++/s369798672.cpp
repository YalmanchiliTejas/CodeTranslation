#include <bits/stdc++.h>
using namespace std;
#define finish(x) reutrn cout << x << endl, 0;
#define ll long long

int d, dp[10001][101][2], mod = 1e9 + 7;
string k;
string c;

int solve(int ind, int cur, int b){
    if(ind == k.size()) return cur == 0;
    int &ret = dp[ind][cur][b];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0 ; i <= (b == 0 ? k[ind] - '0' : 9) ; i++)
        ret = (ret + solve(ind + 1, (cur + i) % d, b || (i < k[ind] - '0'))) % mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> k >> d;
    cout << (solve(0, 0, 0) - 1 + mod) % mod << endl;
}
