#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxN = 3000+10;
const int Mod = 998244353;
int N, S;
int A[MaxN];
int C[MaxN];


void solve()
{
    ll ans = 0;
    for (int k = 1; k <= N; k++) {
        C[0] = (C[0] + 1) % Mod;
        for (int i = S; i >= A[k]; i--)
            C[i] = (C[i] + C[i - A[k]]) % Mod;
        ans = (ans + C[S]) % Mod;
    }
    cout << ans << endl;
}


int main()
{
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> A[i];
    solve();
    return 0;
}
