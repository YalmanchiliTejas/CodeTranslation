#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll i = K + 1; i <= N; i++) {
        ans += (i - K) * (N / i);
        ans += max(ll(0), N % i - K + 1);
        // cout << i << ":" << ans << "\n";
    }

    if (K == 0) ans = N * N;

    cout << ans << "\n";
}