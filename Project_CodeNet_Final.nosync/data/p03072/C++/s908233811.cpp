#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int H[N];
    int ans = 0;
    H[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (int i = 1; i <= N; i++) {
        bool canSeeSea = true;
        for (int j = 0; j < i; j++) {
            if (H[i] < H[j]) {
                canSeeSea = false;
            }
        }
        if (canSeeSea) {
            ans++;
        }
    }
    cout << ans << endl;
}
