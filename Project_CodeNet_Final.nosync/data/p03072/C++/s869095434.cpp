#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 1;
    int h_max;
    cin >> h_max;
    for (int i=0; i<n-1; i++) {
        int h;
        cin >> h;
        if (h_max <= h) {
            ans++;
            h_max = h;
        }
    }

    cout << ans << endl;
}
