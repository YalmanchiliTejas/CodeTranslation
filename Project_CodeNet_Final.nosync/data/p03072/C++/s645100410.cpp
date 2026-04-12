#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0;i < n;i++) cin >> h[i];

    int high = h[0];
    int cnt = 1;
    for (int i = 1;i < n;i++) {
        if (high <= h[i]) {
            cnt++;
            high = h[i];
        }
    }
    cout << cnt << endl;
}
