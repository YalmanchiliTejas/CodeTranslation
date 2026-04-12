#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll dp[10005][105][2];
int to_int(char in){
    return (int)(in - '0');
}

int main() {
    //cout.precision(10);
    string K;
    int D;
    cin >> K >> D;
    int n = K.size();
    dp[n][0][1] = 1;
    for(int index = n; index >= 1; index--){
        for(int modulo = 0; modulo < D; modulo++){
            //cout << index << " " << modulo << " " << dp[index][modulo][0] + dp[index][modulo][1] << endl;
            for(int digit = 0; digit < 10; digit++){
                dp[index - 1][(modulo + digit) % D][0] = (dp[index - 1][(modulo + digit ) % D][0] + dp[index][modulo][0]) % mod;
            }
            int now = to_int(K[n - index]);
            //cout << index - 1 << " " << now << endl;
            dp[index - 1][(modulo + now) % D][1] = (dp[index - 1][(modulo + now) % D][1] + dp[index][modulo][1]) % mod;
            for(int digit = 0; digit < now; digit++){
                dp[index - 1][(modulo + digit) % D][0] = (dp[index - 1][(modulo + digit) % D][0] + dp[index][modulo][1]) % mod;
            }
        }
    }
    cout << (dp[0][0][0] + dp[0][0][1] - 1 + mod) % mod << endl;
    return 0;
}
