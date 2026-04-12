#include<iostream>
using namespace std;

int H[22];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> H[i];
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        bool is_ok = true;
        for (int j = 0; j < i; j++) {
            if (H[i] < H[j]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) ans++;
    }
    cout << ans << endl;
    return 0;
}