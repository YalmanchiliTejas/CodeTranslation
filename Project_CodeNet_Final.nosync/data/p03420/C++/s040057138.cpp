#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long ans = 0;

    for(int b=k+1; b<=n; b++)
    {
        int curr = (n + 1) / b * (b - k);
        curr += max((n + 1) % b - k, 0);

        ans += curr - (k == 0);
    }

    cout << ans << "\n";
    return 0;
}
