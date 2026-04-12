#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

ll N, X, ans;
vector<ll> cnt(51);
vector<ll> pat(51);

void f(ll n, ll x) {
    if (x == 1) {
      if(n==0)ans++;
    } else if (x == 1 + cnt[n - 1] + 1) {
        ans += pat[n - 1] + 1;
    } else if (x == 1 + cnt[n - 1] + 1 + cnt[n - 1] + 1) {
        ans += pat[n];
    } else if (x <= 1 + cnt[n - 1]) {
        f(n - 1, x - 1);
    } else if (x > 1 + cnt[n - 1] + 1) {
        ans += pat[n - 1] + 1;
        f(n - 1, x - (1 + cnt[n - 1] + 1));
    }
}

int main() {
    cin >> N >> X;
    ans    = 0;
    cnt[0] = 1;
    pat[0] = 1;
    for (int i = 1; i <= 50; i++) {
        cnt[i] = 3 + cnt[i - 1] * 2;
        pat[i] = 1 + pat[i - 1] * 2;
    }
    f(N, X);
    cout << ans << endl;
}