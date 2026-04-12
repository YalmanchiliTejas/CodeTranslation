#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
//西暦⇒時代の歴
ll a[100010];
int main()
{
    ll N, K;
    cin >> N >> K;

    if (K == 0)
    {
        cout << N * N << endl;
        return 0;
    }
    ll ans = 0;
    for (ll i = K + 1; i <= N; ++i)
    {
        // aは適当な数字に固定 b = i;
        ans += N / i * (i - K);
        ans += max(0LL, (N % i) - K + 1);
    }
    cout << ans << endl;
    return 0;
}