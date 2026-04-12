#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    int N, H[20];
    cin >> N;
    int x = 0;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        if (x <= H[i]) {
            ans++;
        }
        x = max(x, H[i]);
    }
    cout << ans << endl;
}