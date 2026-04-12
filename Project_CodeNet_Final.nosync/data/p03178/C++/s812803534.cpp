#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>


#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

ll dp[10010][2][100];
const int mod = 1e9+7;

int main(){
    string s;
    int d;
    cin >> s >> d ;
    int n = s.size();
    dp[0][0][0] = 1;
    
    rep(i,n){
        rep(j,2){
            rep(k,d){
                int x = j ? 9 : s[i] - '0';
                for(int num = 0; num <= x; num++){
                    dp[i+1][j || num < x ][(k+num) % d] += dp[i][j][k];
                    dp[i+1][j || num < x ][(k+num) % d] %= mod;
                }
            }
        }
    }
    ll ans = (dp[n][0][0] + dp[n][1][0]) % mod;
    ans = (ans + mod - 1) % mod;
    cout << ans << endl;

    return 0;
}
