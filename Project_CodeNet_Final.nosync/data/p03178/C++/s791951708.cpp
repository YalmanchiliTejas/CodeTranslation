#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;
typedef pair<LL, pii> plpii;
typedef pair<LD, LD> pdd;
typedef pair<LD, int> pdi;
typedef pair<LD, LL> pdl;
typedef pair<int, LD> pid;
typedef pair<LL, LD> pld;
const int mod = 1e9 + 7;
const int hf = 999983;
const int N = 1e6;
char s[10005];
int dp[10005][105];
int d, n;
int dfs(int i, int rem, bool check){
    if(i == n+1){
        if(rem == 0) return 1;
        return 0;
    }

    if(!check && dp[i][rem] != -1) return dp[i][rem];
    int l = 9;
    if(check) l = s[i]-'0';

    int ans = 0;
    for(int j=0;j<=l;j++){
        if(check && j == l) ans = (ans + dfs(i+1, (rem+j)%d, 1))%mod;
        else ans = (ans + dfs(i+1, (rem+j)%d, 0))%mod;
    }
    if(!check) dp[i][rem] = ans;
    return ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%s%d", s+1, &d);
    n = strlen(s+1);
    printf("%d\n", (dfs(1, 0, 1)-1+mod)%mod);
}
