# include <iostream>
# include <algorithm>

using namespace std;

const int INF = 1001001001;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int iter = max(x, y) * 2 + 1;
    
    int cost = INF;
    for (int i = 0; i < iter; ++i) {
        cost = min(cost, a * max(0, x - i/2) + b * max(0, y - i/2) + c*i);
    }

    cout << cost << endl;
    return 0;
}