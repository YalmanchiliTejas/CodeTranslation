#include <iostream>
using namespace std;

int main() {
    int n, ans = 0, max_h = 0, hi;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> hi;
        if (max_h <= hi) {ans++;}
        max_h = max(max_h, hi);
    }

    cout << ans;

}