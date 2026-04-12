//
//  main.cpp
//  DPS2
#include <iostream>
#include <string>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
const int mod = 1e9 + 7;

int main() {
    string A;
    cin >> A;
    ll n = A.length();
    int d;
    cin >> d;
    int dp[10001][2][101]={}; // dp[桁][Aより小さいことが1:確定 0:未定][mod d]
    dp[0][0][0]=1;
    for(ll i=0;i<n;i++){
        rep (j, 2)rep(l,d) {
            int lim=9;
            if (j==0) lim=A[i]-'0';
            rep (now, lim + 1) {
                (dp[i + 1][j || now < lim][(l+now)%d] += dp[i][j][l])%=mod;
            }
        }
    }
    ll ans= -1;
    rep (j, 2)rep(l,d) if(l==0) (ans+=dp[n][j][l])%=mod;
    cout << (ans+mod)%mod << endl;
    return 0;
}
