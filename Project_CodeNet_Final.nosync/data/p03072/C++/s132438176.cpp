#include <iostream>
using namespace std;

int main() {
    int n, h[110];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        bool flag = true;
        for (int j = i - 1; j >= 0; j--) {
            if (h[j] > h[i]) flag = false;
        }
        if (flag) cnt++;
    }

    cout << cnt << endl;
    return 0;
}