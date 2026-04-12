#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0, num1 = 0, num2 = 0;

    ll cnt = 0, now1 = a[0], now2 = a[0], check = 0;
    while (check != n - 1) {
        if (n % 2 == 0 && check == n - 2) {
            // cout << num1 << "\n";
            // cout << a[n - 1 - cnt] << endl;
            num1 += max(abs(now1 - a[n - 1 - cnt]), abs(now2 - a[n - 1 - cnt]));
            break;
        }
        num1 += abs(now1 - a[n - 1 - cnt]);
        now1 = a[n - 1 - cnt];
        cnt++;
        check++;
        num1 += abs(now2 - a[n - 1 - cnt]);
        now2 = a[n - 1 - cnt];
        cnt++;
        check++;

        if (check == n - 1) break;

        cnt -= 2;
        if (n % 2 == 0 && check == n - 2) {
            // cout << num1 << "\n";
            // cout << a[cnt + 1] << endl;
            num1 += max(abs(now1 - a[cnt + 1]), abs(now2 - a[cnt + 1]));
            break;
        }
        num1 += abs(now1 - a[cnt + 1]);
        now1 = a[cnt + 1];
        cnt++;
        check++;
        num1 += abs(now2 - a[cnt + 1]);
        now2 = a[cnt + 1];
        cnt++;
        check++;
    }
    cnt = 0;
    check = 0;
    ll Now1 = a[n - 1], Now2 = a[n - 1];
    while (check != n - 1) {
        if (n % 2 == 0 && check == n - 2) {
            // cout << num2 << "\n";
            num2 += max(abs(Now1 - a[cnt]), abs(Now2 - a[cnt]));
            break;
        }
        num2 += abs(Now1 - a[cnt]);
        Now1 = a[cnt];
        cnt++;
        check++;
        num2 += abs(Now2 - a[cnt]);
        Now2 = a[cnt];
        cnt++;
        check++;

        if (check == n - 1) break;

        cnt -= 2;
        if (n % 2 == 0 && check == n - 2) {
            // cout << num2 << "\n";
            num2 += max(abs(Now1 - a[n - 2 - cnt]), abs(Now2 - a[n - 2 - cnt]));
            break;
        }
        num2 += abs(Now1 - a[n - 2 - cnt]);
        Now1 = a[n - 2 - cnt];
        cnt++;
        check++;
        num2 += abs(Now2 - a[n - 2 - cnt]);
        Now2 = a[n - 2 - cnt];
        cnt++;
        check++;
    }

    // cout << num1 << " " << num2 << "\n";

    ans = max(num1, num2);
    cout << ans << "\n";
    return 0;
}