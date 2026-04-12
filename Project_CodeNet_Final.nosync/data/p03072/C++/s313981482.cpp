#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    long H[20];
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> H[i];
    }

    long H_max = 0;
    long cnt = 0;
    for (long i = 0; i < n; i++) {
        if (H[i] >= H_max) {
            cnt++;
            H_max = H[i];
        }
    }

    cout << cnt << endl;

    return 0;
}
