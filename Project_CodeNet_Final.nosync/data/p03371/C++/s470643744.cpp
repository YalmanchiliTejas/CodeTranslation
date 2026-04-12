#include <bits/stdc++.h>

using namespace std;

// 別解
int main() {
    int64_t A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // 考え方メモ
    // 10^5なので、forは1重まで
    // Cを何個買うか決めれば、残りは決まるので、Cの全てのパターンを洗い出す -> O(N) -> 10^5
    // Cを基準に選んだ理由は、条件がAとBで対称になり実装が楽なため

    int64_t minTotal = 10000000000000;

    for (int i = 0; i <= 100000; i++)
    {
        minTotal = min(minTotal, 2 * C * i + max((int64_t)0, A * (X - i)) + max((int64_t)0, B * (Y - i)));
    }

    cout << minTotal << endl;

    return 0;
}