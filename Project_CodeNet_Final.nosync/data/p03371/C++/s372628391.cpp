#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if(a + b < 2 * c) {
        cout << a * x + b * y << endl;
        return 0;
    }

    int min_ans = min(x, y) * 2 * c + (x - min(x, y)) * a + (y - min(x, y)) * b;
    int max_ans = max(x, y) * 2 * c + max(x - max(x, y), 0) * a + max(y - max(x, y), 0) * b;
    cout << min(min_ans, max_ans) << endl;
    return 0;
}