#include <bits/stdc++.h>
using namespace std;


string s;
int d;
const int mod =1e9+7;

int dp[100009][109] = {-1};

int dfs(int pos, int sum, bool flag) {
    if (pos==s.size()) return sum % d == 0;

    if (!flag && dp[pos][sum]!=-1) {
        return dp[pos][sum];
    }

    int lim = flag ? s[pos] - '0' : 9;

    int ret = 0;

    for (int i = 0; i <= lim; i++) {
        ret += dfs(pos+1, (sum + i)%d, flag&&i==lim);
        ret %= mod;
    }
    
    if(!flag) dp[pos][sum]=ret;
    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin>>s;
    cin>>d;
    cout<<(dfs(0, 0, true)-1+mod)%mod<<endl;
}