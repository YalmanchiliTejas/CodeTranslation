#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, a, b;
    cin >> k >> a >> b;
    if (a >= k) {
        cout << 1 << endl;
        return 0;
    }
    if (b >= a) {
        cout << -1 << endl;
        return 0;
    }
    k -= a;
    cout << ((k + (a - b - 1)) / (a - b)) * 2 + 1 << endl;
}