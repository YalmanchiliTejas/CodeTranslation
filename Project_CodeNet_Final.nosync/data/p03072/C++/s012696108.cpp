#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int hm = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (h >= hm) {
            hm = h;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}