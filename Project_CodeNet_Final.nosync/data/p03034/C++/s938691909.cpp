#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5, mod = 1e9 + 7;

int a[maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n; ++i){
        int l = 0, r = n - 1;
        ll sum = 0;
        while (1){
            l += i, r -= i;
            if (l==r||l-i==r||r<=i) break;
            sum += a[l] + a[r];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
