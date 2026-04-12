#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    long long sum = 0;
    long long x = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + a.at(i) * x) % 1000000007;
        x = (x + a.at(i)) % 1000000007;
    }
    cout << sum % 1000000007 << endl;
    return 0;
}
