#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
const int mod = 1e9+7;

int A[200200], sum[200200];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    for (int i=1; i<=n; i++) cin>>A[i];
    for (int i=1; i<=n; i++) sum[i] = sum[i-1] + A[i];
    int res = 0;
    for (int i=1; i<n; i++) {
        res = ((sum[n] - sum[i])%mod*A[i]%mod + res)%mod;
    }
    cout << res;
    return 0;
}