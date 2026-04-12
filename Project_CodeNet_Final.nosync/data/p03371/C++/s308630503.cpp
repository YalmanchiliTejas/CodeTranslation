// Half and Half

#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

using namespace std;

int main() {
    int A, B, C, X, Y, i, j;
    cin >> A >> B >> C >> X >> Y;

    // 買い方
    // X > Y の場合
    //     1. AピザをX枚、BピザをY枚買う
    //     2. ABピザを 2 * X枚買う
    //     3. ABピザを 2 * Y枚買い、Aピザを(X - Y)枚買う

    int result1, result2, result3;
    if (X > Y) {
        result1 = A * X + B * Y;
        result2 = C * 2 * X;
        result3 = C * 2 * Y + A * (X - Y);
    } else {
        result1 = A * X + B * Y;
        result2 = C * 2 * Y;
        result3 = C * 2 * X + B * (Y - X);
    }

    vector <int> results = {result1, result2, result3};
    int result = *min_element(results.begin(), results.end());

    // for debug
    // cout << "result1: " << result1 << endl;
    // cout << "result2: " << result2 << endl;
    // cout << "result3: " << result3 << endl;

    cout << result << endl;

    return 0;
}
