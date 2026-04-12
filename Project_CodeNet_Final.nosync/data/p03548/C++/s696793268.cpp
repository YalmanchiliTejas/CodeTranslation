#include <bits/stdc++.h>

using namespace std;
int main() {
    int x, y, z;
    int num;
    int rem;

    cin >> x >> y >> z;

    num = 1;
    rem = x - (y + 2*z);

    for (;;) {
        rem -= y + z;
        if (rem >= 0) {
            num++;
        } else {
            break;
        }
    }


    cout << num << endl;
    return 0;
}

