#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // 考え方メモ
    // 10^5なので、forは1重まで
    // Cを何個買うか決めれば、残りは決まるので、Cの全てのパターンを洗い出す -> O(N) -> 10^5
    // Cを基準に選んだ理由は、条件がAとBで対称になり実装が楽なため

    int64_t minTotal = 10000000000000;

    if (X >= Y) {
        for (int i = 0; i <= X; i++) {
            int64_t currentTotal = 0;
            if (Y - i > 0) {
                currentTotal = 2 * C * i + A * (X - i) + B * (Y - i);
            } else {
                currentTotal = 2 * C * i + A * (X - i);
            }
            minTotal = min(minTotal, currentTotal);
        }
    } else {
        for (int i = 0; i <= Y; i++) {
            int64_t currentTotal = 0;
            if (X - i > 0) {
                currentTotal = 2 * C * i + A * (X - i) + B * (Y - i);
            } else {
                currentTotal = 2 * C * i + B * (Y - i);
            }
            minTotal = min(minTotal, currentTotal);
        }
    }

    cout << minTotal << endl;

    return 0;
}