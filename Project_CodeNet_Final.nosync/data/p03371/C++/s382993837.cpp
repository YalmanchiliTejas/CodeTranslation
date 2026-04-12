#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    vector<int> prices(3);
    prices[0] = A * X + B * Y;
    prices[1] = max(2 * C * min(X,Y) + A * (X - Y),  2 * C * min(X,Y) + B * (Y - X));
    prices[2] = max(X, Y) * 2 * C;
    cout << *min_element(prices.begin(), prices.end());
}