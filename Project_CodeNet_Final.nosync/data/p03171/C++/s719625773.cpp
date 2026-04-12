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

bool vis[2][3005][3005];
LL dp[2][3005][3005];
int a[3005], n;

LL dfs(int t, int s, int e){
    if(e-s+1 == 0) return 0;
    if(vis[t][s][e]) return dp[t][s][e];
    vis[t][s][e] = 1;
    if(t == 0) return dp[t][s][e] = max(dfs(1-t, s+1, e) + a[s], dfs(1-t, s, e-1) + a[e]);
    else return dp[t][s][e] = min(dfs(1-t, s+1, e) - a[s], dfs(1-t, s, e-1) - a[e]);
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    printf("%lld\n", dfs(0, 1, n));
}
