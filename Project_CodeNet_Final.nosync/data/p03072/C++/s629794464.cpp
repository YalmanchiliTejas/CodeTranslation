#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    int cur = h[0];
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (cur <= h[i]) {
            cur = h[i];
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
