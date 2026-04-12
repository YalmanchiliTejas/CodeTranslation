#include <iostream>

#define rep(i, N) for (LL i = 0; i < N; ++i)
typedef long long int LL;

using namespace std;

int main() {
    LL N, H[100], r = 1;
    cin >> N;
    rep(i, N) cin >> H[i];
    for (LL i = 1; i < N; ++i) {
        bool check = true;
        if (H[i] < H[0]) check = false;
        for (LL j = 0; j < i; j++) {
            if (H[i] < H[j]) {
                check = false;
            }
        }
        if (check) r++;
    }

    cout << r << endl;
    return 0;
}
