#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    int32_t a[n];
    int32_t b[n];
    for (int32_t i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);

    int32_t l = b[n / 2 - 1];
    int32_t r = b[n / 2];

    for (int32_t i = 0; i < n; i++) {
        if (a[i] <= l) {
            cout << r << endl;
        } else if (a[i] >= r) {
            cout << l << endl;
        }
    }

    return 0;
}
