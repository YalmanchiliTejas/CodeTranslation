#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

bool count(long long n, vector<long long> &v) {
    long long add = 0;
    for (long long i = 0; i < n; i++) {
        if (v[i] >= n) {
            add += v[i] / n;
            v[i] = (v[i] % n) - v[i] / n;
        }
    }
    for (long long i = 0; i < n; i++) {
        v[i] += add;
    }
    ans += add;
    return add;
}

int main() {
    long long n; cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    while (count(n, v));
    cout << ans << endl;
    return 0;
}