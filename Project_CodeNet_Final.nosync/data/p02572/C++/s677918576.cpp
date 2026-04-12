#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

const int mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 0;
    int x = 0;

    rep(i, N) {
        ans = (ans + (ll)A[i] * x) % mod;
        x = (x + A[i]) % mod;
    }
    
    cout << ans << endl;

    return 0;
}