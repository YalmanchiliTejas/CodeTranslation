#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> p(n + 1), num(n + 1);
    p[0] = 1;
    num[0] = 1;
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] * 2 + 1;
        num[i + 1] = num[i] * 2 + 3;
    }
    long long ans = 0;
    while (x > 0) {
        --x;
        if (num[n - 1] <= x) {
            ans += p[n - 1];
            x -= num[n - 1];
        }
        else {
            --n;
            continue;
        }
        if (x > 0) {
            --x;
            ++ans;
        }
        else {
            --n;
            continue;
        }
        if (num[n - 1] <= x) {
            ans += p[n - 1];
            x -= num[n - 1];
        }
        else {
            --n;
            continue;
        }
        --x;
    }
    cout << ans << "\n";
    return 0;
}
