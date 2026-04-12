#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int count = 0;
    int max_h = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (max_h <= x) {
            max_h = x;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
