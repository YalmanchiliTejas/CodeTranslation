#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B <= 2 * C) {
        cout << A * X + B * Y << endl;
        return 0;
    }
    int cost1 = 2 * X * C + max(Y - X, 0) * B;
    int cost2 = 2 * Y * C + max(X - Y, 0) * A;
    cout << min(cost1, cost2) << endl;
    return 0;
}
