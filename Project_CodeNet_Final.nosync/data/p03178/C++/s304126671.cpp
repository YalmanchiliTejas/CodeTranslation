#include <bits/stdc++.h>
#define rep(i,a ,b) for(int i = a; i < (b); ++i)
using namespace std;
 
const int INF = 0x3f3f3f3f;
const int MAXD = 123;
const int MAXK = 112345;
const int mod = 1e9+7;
 
char ent[MAXK];
int d, n;
int dp[MAXK][MAXD][2];
string numStr;
 
int rec(int k, int s, int edge){
    if (k == n) return (s % d) == 0;
    if (dp[k][s][edge] != -1) return dp[k][s][edge];
    int lim = 9, resp = 0;
    if (edge) lim = ent[k] - '0';
    rep(i, 0, lim + 1){
        int nedge = edge && (i == lim);
        resp += rec(k + 1, (s + i) % d, nedge);
        resp %= mod;
    }
    return dp[k][s][edge] = resp;
}
 
int main()
{
    scanf("%s\n%d", ent, &d);
    n = strlen(ent);
 
    memset(dp, -1, sizeof(dp));
 
    int resp = 0;
    for(int i=0; i<(ent[0]-'0'); i++){
        resp += rec(1,i%d,0);
        resp %= mod;
    }
    resp += rec(1,(ent[0]-'0')%d,1);
    resp %= mod;
    cout <<  ((resp-1) % mod  < 0 ? (resp-1) % mod + mod : (resp-1) % mod) << '\n';
    return 0;
}