#include <iostream>

using namespace std;

int main() {
    int N, H, h, ret = 1;
    cin >> N;
    cin >> h;
    while (--N) {
        cin >> H;
        if (H >= h) {
            h = H;
            ++ret;
        }
    }
    cout << ret << endl;
    return 0;
}