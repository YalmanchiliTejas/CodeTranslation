#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    long long ans = 0;
    
    if (k == 0) {
        cout << (long long)n * n << endl;
        return 0;
    }
    
    for(int b = 1; b <= n; b++)
    {
        if (b <= k) continue;

        int loop = n / b;
        ans += loop * (b - k);

        if (n % b >= k) ans += (n % b) - k + 1;
    }
    cout << ans << endl;
}