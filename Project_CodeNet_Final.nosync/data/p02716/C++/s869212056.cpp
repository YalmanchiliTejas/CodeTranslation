#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxN = 2e5+10;
int N;
int A[MaxN];


void solve()
{
    vector<ll> prefix(N + 1);
    vector<ll> f(N + 1);
    prefix[1] = A[1];
    for (int i = 3; i <= N; i += 2)
        prefix[i] = prefix[i - 2] + A[i];
    for (int n = 2; n <= N; n++) {
        if (n & 1)
            f[n] = max(f[n - 1], A[n] + f[n - 2]);
        else
            f[n] = max(prefix[n - 1], A[n] + f[n - 2]);
    }
    cout << f[N] << endl;
}


int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    solve();
    return 0;
}
