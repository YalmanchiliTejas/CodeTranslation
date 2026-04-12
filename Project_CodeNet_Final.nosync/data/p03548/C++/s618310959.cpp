#include <iostream>
using namespace std;

int main(void) {
    int x, y, z, cnt = 0;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> x >> y >> z;
    while (true) {
        int width = y * cnt + z * (cnt + 1);
        if (x < width) {
            cnt--;
            break;
        }

        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}