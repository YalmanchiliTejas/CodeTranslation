#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n, a, b, c, x;
        cin >> n >> a >> b >> c >> x;
        if ((n | a | b | c | x) == 0) {
            break;
        }
        int* randomNums = new int [n];
        for (int i = 0; i < n; i++) {
            cin >> randomNums[i];
        }
        int reel = 0, time = 0;
        while (reel < n && time <= 10001) {
            if (randomNums[reel] == x) {
                reel++;
            }
            x = (a * x + b) % c;
            time++;
        }
        if (time <= 10001) {
            cout << time - 1 << endl;
        } else {
            cout << -1 << endl;
        }
        delete[] randomNums;
    }
}