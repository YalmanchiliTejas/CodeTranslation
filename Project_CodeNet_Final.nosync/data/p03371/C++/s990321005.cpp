#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int A, B, C, X, Y, x = 0, y = 0, totalCost = 0;
    cin >> A >> B >> C >> X >> Y;
    while (x < X && y < Y) {
        if (A + B < 2 * C) {
            totalCost += A + B;
        } else {
            totalCost += 2 * C;
        }
        x++; y++;
    }
    while (x < X) {
        if (A < 2 * C) {
            totalCost += A;
        } else {
            totalCost += 2 * C;
        }
        x++;
    }
    while (y < Y) {
        if (B < 2 * C) {
            totalCost += B;
        } else {
            totalCost += 2 * C;
        }
        y++;
    }
    cout << totalCost << endl;
    return 0;
}

