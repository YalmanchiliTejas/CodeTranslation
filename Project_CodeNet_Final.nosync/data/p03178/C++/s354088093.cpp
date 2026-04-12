#include <bits/stdc++.h>
#define mn(a, b) (a < b ? a : b)
#define mx(a, b) (a > b ? a : b)
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define base 331

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int const MAXn = 1e4 + 2, MOD = 1e9 + 7;

ll dp[MAXn][102][11];

int main(){

    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string k;
    int d;
    cin>>k>>d;
    dp[0][0][0] = 1;
    reverse(all(k));
    int ts = k.size();
    k = "0" + k;
    for(int i = 1; i <= ts; i++){
        for(int m = 0; m < d; m++){
            for(int l = 0; l <= 9; l++){
                for(int o = 0; o <= 9; o++)
                    dp[i][(m + l) % d][l] = (dp[i][(m + l) % d][l] + dp[i - 1][m][o]) % MOD;
            }
        }
    }
    ll sol = 0;
    int sum = 0;
    for(int i = ts; i >= 1; i--){
        for(int y = 0; y < k[i] - '0'; y++){
            sol = (sol + dp[i][(d - sum) % d][y]) % MOD;
        }
        sum = (sum + k[i] - '0') % d;
    }
    if(sum){
        sol = (sol - 1 + MOD) % MOD;
    }
    cout<<sol;
    return 0;
}
