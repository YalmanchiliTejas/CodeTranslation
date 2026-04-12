#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
template<class T> void chmin(T& x, T y){if(x < y) x = y;}
template<class T> void chmax(T& x, T y){if(x > y) x = y;}
int N;
int S;
const ll mod = 998244353;
int A[3010];
ll dp[3010][3010];

int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        dp[i][0] += 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < S; j++){
            int to = j + A[i];
            if(to <= S){
                dp[i + 1][to] += dp[i][j];
                dp[i + 1][to] %= mod;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= N + 1; i++){
        ans += dp[i][S] * (ll)(N - i + 2);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}