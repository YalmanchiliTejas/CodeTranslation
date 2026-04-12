#include <bits/stdc++.h>

using namespace std;

int m = 1000000007;

int addMod(int a, int b) {
    return (a % m + b % m) % m;
}

int subMod(int a, int b) {
    int x = (a % m - b % m) % m;
    if (x < 0) {
        x += m;
    }
    return x;
}

int multMod(int a, int b) {
    return (int)(((long long)(a % m) * (b % m)) % m);
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sums[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        sums[i + 1] = addMod(sums[i], a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = addMod(ans, multMod(a[i], subMod(sums[n], sums[i + 1])));
    }
    
    cout << ans << "\n";
}