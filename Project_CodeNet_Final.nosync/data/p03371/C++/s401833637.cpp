#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // 考え方メモ
    // 具体例(1500,2000,1600,3,2)
    // Aピザ：1500, Bピザ：2000, Cピザ:1600, A -> A, B -> B, C -> 0.5A + 0.5B
    // XはAの枚数、YはBの枚数
    // Cは0.5枚 -> Cは偶数個 -> 2C
    // １つ当たりAとBそれぞれ買った時と2Cで買った時の値段がどちらが大きいか？ -> 場合分け

    int64_t minTotal = 0;
    if (2 * C >= A + B) {  // Cの方が高い場合 -> Cを使わない
        minTotal = A * X + B * Y;
    } else {  // Cの方が安い場合 -> 1. Cを買い、残りはA,Bそれぞれ買う or 2. Cのみで買う

        // パターン1：A, B, C の組み合わせ
        int minXY = min(X, Y);
        int64_t minTotal1 = A * (X - minXY) + B * (Y - minXY) + C * 2 * minXY;

        // パターン2：Cのみで買う
        int maxXY = max(X, Y);
        int64_t minTotal2 = C * 2 * maxXY;

        minTotal = min(minTotal1, minTotal2);
    }

    cout << minTotal << endl;

    return 0;
}