#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main()
{
    ll N;
    cin >> N;
    vector<ll> A;
    vector<ll> B(N + 1, 0);
    B[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        A.push_back(temp);
        B[i + 1] = B[i] + A[i];
    }
    ll ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        ll sum = (B[N] - B[i + 1]) % MOD;
        ans += A[i] * sum;
        ans = ans % MOD;
    }
    cout << ans << endl;
}
