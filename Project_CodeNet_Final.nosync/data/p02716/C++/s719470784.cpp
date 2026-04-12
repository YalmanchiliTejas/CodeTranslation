
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200001;
int n;
int a[N];
ll dp[N];
ll S[N / 2 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll sum = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) {
            sum += a[i];
            S[j++] = sum;
        }
    }

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        // select half of i + 1
        if ((i + 1) % 2) {
            // 2 of 5
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        } else {
            // 2 of 4
            dp[i] = max(dp[i - 2] + a[i], S[i / 2]);
        }
    }
    cout << dp[n - 1] << endl;

    return 0;
}

