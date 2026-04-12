#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

char s[105];
ll dp[105][105];
int N, K;
ll dfs(int i, int k, int p){
    if(i == N+1){
        if(k == K) return 1;
        return 0;
    }
    if(p == 0 && dp[i][k] != -1) return dp[i][k];
    int last = 9;
    if(p == 1) last = s[i]-'0';
    ll ans = 0;
    for(int j=0;j<=last;j++){
        int add = 0;
        if(j != 0) add = 1;
        if(p == 1 && j == last) ans += dfs(i+1, k+add, 1);
        else ans += dfs(i+1, k+add, 0);
    }
    if(p == 0) dp[i][k] = ans;
    return ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%s", s+1);
    N = strlen(s+1);
    scanf("%d", &K);
    printf("%lld\n", dfs(1, 0, 1));
}