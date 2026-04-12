#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int ans = 0, maxH = 0;
    for (int i = 0; i < N; i++) {
        int H; cin >> H;
        if (H >= maxH) {
            maxH = H;
            ans++;
        }
    }
    cout << ans << "\n";
}