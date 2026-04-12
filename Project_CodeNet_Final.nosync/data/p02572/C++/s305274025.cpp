#include <iostream>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main(void)
{
    int N;
    ll A[200005], t = 0, t2 = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        t += A[i];
        t %= mod;
        t2 = t2 + ((A[i] % mod) * (A[i] % mod)) % mod;
        t2 %= mod;
    }
    ll ans = (((t * t) % mod) + (mod - t2)) % mod;
    if (ans < 0) {
        ans += mod;
    }
    ans *= (mod + 1) / 2;
    cout << ans % mod << endl;
    return 0;
}