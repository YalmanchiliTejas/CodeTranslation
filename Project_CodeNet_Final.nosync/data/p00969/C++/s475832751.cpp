#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

bool ok[1000000010];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) {
        cin >> v[i];
        ok[v[i]]=true;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    rep(i, n) {
        if (ans >= n-i-1) break;
        for (int j=i+1; j<n; ++j) {
            if (ans >= 2+n-j-1) break;
            ll d = v[j]-v[i];
            ll prev = v[j];
            ll num = 2;
            while (prev+d <= 1000000000 and ok[prev+d]) {
                num++;
                prev += d;
            }
            ans = max(ans, num);
            if (ans >= n-i-1) break;
        }
    }
    cout << ans << endl;
}

