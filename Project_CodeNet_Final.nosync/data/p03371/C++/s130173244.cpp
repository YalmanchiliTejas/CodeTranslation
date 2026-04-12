#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int answer;
    if (a <= c && b <= c) {
        answer = a * x + b * y;
    } else if (a > c && b > c) {
        if (x >= y) {
            answer = c * 2 * y + min(a * (x - y), c * 2 * (x - y));
        } else {
            answer = c * 2 * x + min(b * (y - x), c * 2 * (y - x));
        }
    } else if (a > c && b <= c) {
        if ((a + b) >= 2 * c) {
            if (x >= y) {
                answer = c * 2 * y + min(a * (x - y), c * 2 * (x - y));
            } else {
                answer = c * 2 * x + b * (y - x);
            }
        } else {
            if (x >= y) {
                answer = a * y + b * y + min(a * (x - y), c * 2 * (x - y));
            } else {
                answer = a * x + b * y;
            }
        }
    } else if (a <= c && b > c) {
        if ((a + b) >= 2 * c) {
            if (x >= y) {
                answer = c * 2 * y + a * (x - y);
            } else {
                answer = c * 2 * x + min(b * (y - x), c * 2 * (y - x));
            }
        } else {
            if (x >= y) {
                answer = a * x + b * y;
            } else {
                answer = a * x + b * x + min(a * (y - x), c * 2 * (y - x));
            }
        }
    }
    cout << answer << endl;
}