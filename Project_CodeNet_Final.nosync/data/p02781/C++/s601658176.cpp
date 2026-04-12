#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int k;

int main() {
    cin >> s;
    cin >> k;
    ll ans = 0;
    if (k == 1) {
        int kk = (s[0] - '0');
        ans = kk;
        ll n = s.size() - 1;
        ans += 9LL * n;
        cout << ans << endl;
        return 0;
    }    

    if (s.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    if (k == 2) {
        ll l = (s[0] - '0');
        ans += (l - 1) * 9LL * (ll)(s.size() - 1);

        ll sz = s.size();
        if (s.size() > 2) {
            ans += (sz - 1) * (sz - 2) / 2 * 9 * 9;
        }

        int posb = 1;
        while (posb < sz && s[posb] == '0') posb++;
        if (posb == sz) {
            cout << ans << endl;
            return 0;
        }
        l = (s[posb] - '0');
        ans += l;
        ans += (sz - posb - 1) * 9LL;

        cout << ans << endl;
        return 0;
    }

    if (s.size() < 3) {
        cout << 0 << endl;
        return 0;
    }

    ll a = (s[0] - '0');
    ll sz = s.size();
    ans += (a - 1) * (sz - 1) * (sz - 2) * 9 * 9 / 2;

    if (sz > 3) {
        ans += (sz - 1) * (sz - 2) * (sz - 3) / 6 * 9 * 9 * 9;
    }

    int posb = 1;
    while (posb < sz - 1 && s[posb] == '0') posb++;
    if (posb == sz - 1) {
        cout << ans << endl;
        return 0;
    }

    ll b = (s[posb] - '0');
    ans += (b - 1) * (sz - posb - 1) * 9;

    if (sz - posb - 1 >= 2) {
        ans += (sz - posb - 1) * (sz - posb - 2) / 2 * 9 * 9;
    }

    int posc = posb + 1;
    while (posc < sz && s[posc] == '0') posc++;
    if (posc == sz) {
        cout << ans << endl;
        return 0;
    }

    ll c = (s[posc] - '0');
    ans += c;
    ans += (sz - posc - 1) * 9;
    cout << ans << endl;
    return 0;
}