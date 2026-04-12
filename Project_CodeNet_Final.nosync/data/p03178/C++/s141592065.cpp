
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int k, mod = 1e9+7;
int newdp[105], olddp[105];
int dp[100005][105][2];

int go(int pos, int sum, int isbigger){
    if(pos == s.size()) return (sum == 0);
    if(dp[pos][sum][isbigger] != -1) return dp[pos][sum][isbigger];
    int res = 0;
    for(int i = (isbigger ? s[pos]-'0' : 9); i >= 0; i--)
        res = (res+go(pos+1, (sum + i)%k, (isbigger&(i == (s[pos]-'0')))))%mod;
    return dp[pos][sum][isbigger] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> s >> k;
    int res = (go(0,0,1)-1+mod)%mod;
    cout << res << endl;
    return 0;
}