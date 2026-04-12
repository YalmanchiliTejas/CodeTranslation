#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for(int i = 0; i < n; i++) cin >> d[i];
    int ma = 0;
    for(int i = 0; i < n; i++) {
        ma = max(ma, 10 * (i - 1) + d[i - 1]);
        if(10 * i > ma) {
            cout << "no" << endl;
            return 0;
        }
    }

    ma = 0;
    for(int i = n - 1; i >= 0; i--) {
        ma = max(ma, 10 * (n - i - 1) + d[i]);
        // cout << ma << " " << 10 * (n - i - 1) << endl;
        if(10 * (n - i) > ma) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}
