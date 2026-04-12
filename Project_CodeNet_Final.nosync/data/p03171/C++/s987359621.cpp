#include <bits/stdc++.h>
#define ll long long
#define name "lqdoj"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ini freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
using namespace std;

const int MOD = 1e9 + 7;
const int NMAX = 3000 + 5;
const int TMAX = 5e4;
int n, a[NMAX];
long long dp[NMAX][NMAX];
int main(){
    fastio;
    //ini;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= n; j++){
            dp[i][j] = (i == j) ? a[i] : max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }

    cout << dp[1][n] << " ";
    return 0;
}



