#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, n, h_max, cnt = 1;

    cin >> n >> h_max;

    for (int i = 0; i < n - 1; i++) {
        cin >> a;

        if (a >= h_max) {
            h_max = a;
            cnt++;
        }
    }

    cout << cnt << endl;
}