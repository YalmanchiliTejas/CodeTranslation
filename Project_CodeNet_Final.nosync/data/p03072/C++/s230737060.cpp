#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;

    int max = 0;
    int ans = 0;

    int H;
    for (int i = 0; i < N; ++i) {
        cin >> H;
        if (H >= max) {
            ans++;
            max = H;
        }
    }

    cout << ans;
}