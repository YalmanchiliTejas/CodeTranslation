#include <bits/stdc++.h>
using namespace std;
int n;
long long a[50];
long long b[50];
long long sum;
bool check(long long t) {
    long long sum1 = 0;
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] + t) % (n + 1);
        //cout << b[i];
        if (b[i] >= n) return false;
        sum1 += b[i];
    }
    if (sum - t == (sum1)) return true;
    return false;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
    }
    check(3);
    for (long long i = max(sum - 50 * 50, 1LL * 0); i <= sum; i++) {
        if (check(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}
