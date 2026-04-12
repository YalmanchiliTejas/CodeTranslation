#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> r(n);

    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    int MAX = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] >= MAX) {
            ans++;
        }
        MAX = max(MAX, r[i]);
    }

    cout << ans << endl;

    return 0;
}   