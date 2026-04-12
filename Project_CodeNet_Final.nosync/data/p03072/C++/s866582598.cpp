#include<iostream>

using namespace std;
int op[200];

int main() {
    int n, x, y, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> op[i];
    for (int i = 2; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j < i; j++)
            if (op[j] > op[i]) {
                flag = false;
                break;
            }
        if (flag)ans++;
    }
    cout << ans;
    return 0;
}