#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+87;
int n;
ll s[N],f[N],g[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    --n;
    ll ans = 0;
    for (int c = 1; c < n; ++c) {
        for (int i = 1; i * c <= n; ++i) 
            f[i] = f[i-1] + s[i*c];
        g[0] = s[n%c];
        int j=0;
        for (int i = 1; n%c+i * c <= n; ++i) {
            g[i] = g[i-1] + s[i*c+n%c];
            j = i;
        }
        for (int a = n%c; a < n; a += c) {
            if (a <= c)
                continue;
            int k = (n-a)/c;
            int l = a/c-1;
            if (n%c != 0 || l+1>k)
                ans = max(ans, f[k] + g[j] - (l>=0?g[l]:0));
        }
    }
    cout << ans << endl;
}
