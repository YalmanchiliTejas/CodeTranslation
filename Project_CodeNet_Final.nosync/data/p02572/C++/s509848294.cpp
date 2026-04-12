#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    int mod = 1e9+7;
    vector<int> A(n);
    rep(i,n) {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }
    ll ans = 0;
    rep(i,n) {
        sum -= A[i];
        if (sum < 0) sum += mod;
        ans += A[i] * sum;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
