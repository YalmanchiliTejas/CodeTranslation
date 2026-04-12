#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll a[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];

    ll sum = 0, ans = 0;
    for (int i=0;i<n;i++) {
        ans += sum*a[i]%1000000007;
        ans %= 1000000007;
        sum += a[i];
        sum %= 1000000007;
    }
    cout << ans << endl;
}
