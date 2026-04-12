/**
 * @author torith
 * @date 2019-02-03
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll a, ll r) {
    ll sum = 1;
    while (r > 0) {
        if ((r & 1) == 1) {
            sum *= a;
        }
        a *= a;
        r >>= 1;
    }
    return sum;
}

ll solve(ll N, ll X){
    ll len_n_1 = 4 * power(2, N-2) - 3;
    if(N == 1 && X == 1) return 1;
    if(X <= 1) return 0;
    else if(X <= len_n_1 + 1) return solve(N-1, X-1);
    else if(X == len_n_1 + 2) return 1 + 2 * power(2, N-2) - 1;
    else if(X <= 2 * len_n_1 + 2) return 1 + 2 * power(2, N-2) - 1 + solve(N-1, X-len_n_1-2);
    else return 2 * power(2, N-1) - 1;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N; cin >> N;
    ll K; cin >> K;

    cout << solve(N+1, K) << "\n";

    return 0;
}

