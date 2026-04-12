#include <iostream>

using namespace std;

int main() {
    int n;
    long long* a;
    cin >> n;
    a = new long long[n];
    long long wa = 0;;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        wa += a[i];
        wa %= 1000000007;
    }

    long long result = 0;
    for (int i = 1; i < n; i++) {
        wa -= a[i];
        while (wa < 0) {
            wa += 1000000007;
        }
        result += a[i] * wa;
        result %= 1000000007;
    }

    cout << result << endl;

    delete[] a;
    return 0;
}