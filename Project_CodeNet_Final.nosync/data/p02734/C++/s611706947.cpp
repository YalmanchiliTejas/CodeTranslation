#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll dp[3005];
ll dp_[3005];
int N, S;
int A[3000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= S; j++){
            dp_[j] = dp[j];
        }
        dp_[A[i]] += (i+1);
        for(int j = 0; j+A[i] <= S; j++){
            dp_[j+A[i]] += dp[j];
        }
        for(int j = 0; j <= S; j++){
            dp[j] = dp_[j];
            dp[j] %= MOD;
            // cout << dp[j] << ' ';
        }
        // cout << endl;
        ans += dp_[S];
        ans %= MOD;
    }
    cout << ans << endl;
}