#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // まずAとBをmin(X, Y)枚を用意
    int min_XY = (X < Y) ? X : Y;
    // この時AとBを1枚ずつ買うか，ABを買うかを選択
    int result = 0;
    if (A+B < C*2) {
        result += min_XY * (A + B);
    } else {
        result += min_XY * C * 2;
    }

    // 残りのAまたはBを購入
    if (X < Y) {
        // B
        int need = Y - X;
        if (B < C*2) {
            result += need * B;
        } else {
            result += need * C*2;
        }
    } else {
        // A
        int need = X - Y;
        if (A < C*2) {
            result += need * A;
        } else {
            result += need * C*2;
        }
    }

    cout << result << endl;
    return 0;
}
