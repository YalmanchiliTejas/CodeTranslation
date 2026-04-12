#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;

    long long ans = 0;
    for (int b=k+1; b<=n; b++) {
        ans += (b-k) * (n/b);
        if (n%b >= k) ans += n%b + min(0, 1-k);
    }

    cout << ans << '\n';
}