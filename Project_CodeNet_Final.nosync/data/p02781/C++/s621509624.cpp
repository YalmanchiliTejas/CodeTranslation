#include "bits/stdc++.h"
#define ll long long
using namespace std;

#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i,b) for(ll i=0;i<b;i++)

int m;

ll solve(string n) {
    ll L = n.size();
    vvvl dp(L + 1, vvl(2, vl(L + 1, 0)));
    dp[0][0][0] = 1;

    rep(i,L) {
        ll D = n[i] - '0';
        rep(j,2) {
            rep(k,L) {
                rep(d,(j?10:D+1)){
                    if(d != 0)dp[i+1][j || (d < D)][k + 1] += dp[i][j][k];
                    else dp[i+1][j || (d < D)][k] += dp[i][j][k];
                }
            }
        }
    }
    return dp[L][0][m] + dp[L][1][m];
}

int main(void) {
    string n;
    cin >> n >> m;
    cout<<solve(n)<<endl;
}