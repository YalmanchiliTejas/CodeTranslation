#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, K;
    ll ans = 0;
    cin >> N >> K;
    
    for (int b = K+1; b <= N; b++) {
        ll a = N%b;
        ll cnt = N/b;
        ans += cnt * (b-K);
        if (a != 0 && a >= K) {
            if (K == 0) {
                ans += a;
            } else {
                ans += (a-K+1);
            }
        }
    }
    cout << ans << endl;
}
