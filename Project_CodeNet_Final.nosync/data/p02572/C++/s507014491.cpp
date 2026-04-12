#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long over = 1000000007;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        sum += a.at(i);
    }

    long long res = 0, tmp, sum_m;
    for (int i = 0; i < n-1; i++) {
        sum -= a.at(i);
        sum_m = sum % over;
        res += a.at(i) * sum_m;
        res = res % over;
    }

    cout << res << endl;

    return 0;
}
