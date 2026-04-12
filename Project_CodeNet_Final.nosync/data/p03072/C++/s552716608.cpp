#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, h[20];

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> h[i];
    }

    int big = h[0], ans = 1;
    for (int i=1; i<n; i++) {
        if (h[i] >= big) {
            ans++;
            big = h[i];
        }
    }

    cout << ans << endl;

    return 0;
}