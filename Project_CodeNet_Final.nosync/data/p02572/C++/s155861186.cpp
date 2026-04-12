#include <bits/stdc++.h>
#define INF 1e9
#define MOD 1000000007
using namespace std;
using ll = long long;

int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll allSum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        allSum += A[i];
    }
    
    ll ans = 0;
    for (int i = 0; i < N-1; i++)
    {
        allSum-=A[i];
        ans += ((allSum % MOD) * A[i])%MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;

    return 0;
}
