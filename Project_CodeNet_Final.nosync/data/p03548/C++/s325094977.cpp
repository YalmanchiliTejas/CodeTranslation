#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int X, Y, Z;

int main() {
    cin >> X >> Y >> Z;

    int cnt = 0;
    while (X >= Z + (Z + Y)*cnt) {
        cnt++;
    }

    cout << cnt - 1 << endl;

    return 0;
}
