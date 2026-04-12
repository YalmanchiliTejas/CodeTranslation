#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    vll b(n / 2), c(n / 2);

    if (n % 2) {
        vll sum(4, 0);

        for (int i = 0; i < n / 2; i++) {
            b[i] = a[i];
            c[i] = a[i + n / 2 + 1];
        }

        ll t = a[n / 2];

        for (int i = 0; i < n / 2; i++) {
            sum[0] += abs(c[i] - b[i]);

            if (i + 1 < n / 2) {
                sum[0] += abs(b[i] - c[i + 1]);
            }
            if (i == 0) {
                sum[0] += abs(t - c[i]);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            sum[1] += abs(c[i] - b[i]);

            if (i + 1 < n / 2) {
                sum[1] += abs(b[i] - c[i + 1]);
            } else {
                sum[1] += abs(b[i] - t);
            }
        }

        sort(b.begin(), b.end(), greater<ll>());

        for (int i = 0; i < n / 2; i++) {
            sum[2] += abs(b[i] - c[i]);

            if (i + 1 < n / 2) {
                sum[2] += abs(c[i] - b[i + 1]);
            } else {
                sum[2] += abs(c[i] - t);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            sum[3] += abs(c[i] - b[i]);

            if (i + 1 < n / 2) {
                sum[3] += abs(b[i] - c[i + 1]);
            } else {
                sum[3] += abs(b[i] - t);
            }
        }

        cout << *max_element(sum.begin(), sum.end()) << endl;

    } else {
        vll sum(4, 0);

        for (int i = 0; i < n / 2; i++) {
            b[i] = a[i];
            c[i] = a[i + n / 2];
        }

        for (int i = 0; i < n / 2; i++) {
            sum[0] += abs(c[i] - b[i]);

            if (i + 1 < n / 2) {
                sum[0] += abs(b[i] - c[i + 1]);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            sum[1] += abs(b[i] - c[i]);

            if (i + 1 < n / 2) {
                sum[1] += abs(c[i] - b[i + 1]);
            }
        }

        sort(b.begin(), b.end(), greater<ll>());

        for (int i = 0; i < n / 2; i++) {
            sum[2] += abs(c[i] - b[i]);

            if (i + 1 < n / 2) {
                sum[2] += abs(b[i] - c[i + 1]);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            sum[3] += abs(b[i] - c[i]);

            if (i + 1 < n / 2) {
                sum[3] += abs(c[i] - b[i + 1]);
            }
        }

        cout << *max_element(sum.begin(), sum.end()) << endl;
    }
}