#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    while (true) {
        int n, a, b, c, x;
        cin >> n >> a >> b >> c >> x;
        if (n == 0 and a == 0 and b == 0 and c == 0 and x == 0) {
            break;
        }
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        int j = 0;
        bool flag = true;
        int turn = 0;
        for (int i = 0; i <= 10000; i++) {
            if (val[j] == x) {
                j++;
                if (j == n) {
                    flag = false;
                    turn = i;
                    break;
                }
            }
            x = (a * x + b) % c;
        }
        if (flag) {
            cout << -1 << endl;
        } else {
            cout << turn << endl;
        }
    }
    return 0;
}