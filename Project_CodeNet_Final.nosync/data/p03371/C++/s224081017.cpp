#include<iostream>
using namespace std;
int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (c <= a && c <= b) {
        if (x >= y) {
            ans = min(x * c * 2, y * 2 * c + (x - y) * a);
        } else {
            ans = min(y * c * 2, x * 2 * c + (y - x) * b);
        }
    } else if (a <= c && b <= c) {
        ans += x * a + y * b;
    } else {
        if (b < a) {
            swap(a, b);
            swap(x, y);
        }
        //a <= c <= b
        if (x > y) {
            ans += (x - y) * a;
            double min = 5000 * 1e5;
            int key = 2 * c > b ? b : 2 * c;
            for (int i = 0; i <= y; ++i) {
                double price = i * ((double)(a + key) / 2) + (y - i) * c;
                //cout << price << endl;
                min = min > price ? price : min;
            }
            ans += 2 * min;
        } else {
            int key = 2 * c > b ? b : 2 * c;
            ans += (y - x) * key;
            //cout << ans << endl;
            double min = 5000 * 1e5;
            for (int i = 0; i <= x; ++i) {
                double price = i * ((double)(a + key) / 2) + (x - i) * c;
                //cout << price << endl;
                min = min > price ? price : min;
            }
            ans += 2 * min;
        }
    }
    cout << ans << endl;
    return 0;
}


