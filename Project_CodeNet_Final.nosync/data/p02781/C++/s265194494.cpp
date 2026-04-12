#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

ll C(int n, int k)
{
    ll res = 1;
    for (int i = 0; i < k; i++) res *= (n - i);
    for (int i = 1; i <= k; i++) res /= i;
    return res;
}

int pow(int n, int k)
{
    int res = 1;
    for (int i = 0; i < k; i++) res *= n;
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string n; cin >> n;
    int k; cin >> k;

    int len = n.length();
    if (len < k) {
        cout << 0 << endl;
    } else {
        ll ans = 0;
        int pos = 0;
        while (pos < len && k > 0) {
            int head = n[pos] - '0';
            if (len - pos - 1 >= k) ans += (ll)pow(9, k) * C(len - pos - 1, k);
            if (len - pos - 1 >= k - 1) ans += (ll)pow(9, k - 1) * (head - 1) * C(len - pos - 1, k - 1);
            while (++pos < len && n[pos] == '0') ;
            k--;
        }
        if (!k) ans++;
        cout << ans << endl;
    }
    return 0;
}