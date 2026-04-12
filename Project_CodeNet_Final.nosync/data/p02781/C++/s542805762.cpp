#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;

ll dp[110][2][110]; // pos, flag, count 1
int main(){
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;

    rep(i, 110)rep(j, 2)rep(k, 110) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i, n)rep(j, 2)rep(k, i + 1){
        int lim = j ? 9 : s[i] - '0';
        rep(d, lim + 1){
            dp[i + 1][j or d < lim][k + ((d != 0) ? 1 : 0)] += dp[i][j][k];
        }
    }
    ll ans = 0;
    rep(j, 2) ans += dp[n][j][k];
    cout << ans << endl;
    return 0;
}