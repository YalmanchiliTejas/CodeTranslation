#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_h = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (max_h <= h) {
            max_h = h;
            ans++;
        }
    }
    cout << ans << endl;
}