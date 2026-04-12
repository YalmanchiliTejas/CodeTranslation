#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

typedef long long ll;

int n, s[MAX_N];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    // ab = a - b (a > b)
    for (int ab = 1; ab <= n; ab++) {
        ll cur = 0;
        for (int k = 0; k * ab < n - 1; k++) {
            int l = k * ab; // 0, ab, 2ab, …, kab
            int r = n - 1 - k * ab; // A, A+ab, A+2ab, …, A+kab
            if ((n - 1) % ab == 0 && l >= r) break;
            if (r <= ab) break;
            cur += s[l] + s[r];
            ans = max(ans, cur);
        }
    }
    cout << ans;
}

