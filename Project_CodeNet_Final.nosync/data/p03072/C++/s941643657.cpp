#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, i, t, ans = -1, cnt = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> t;
        if (ans <= t) {
            ans = t;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}