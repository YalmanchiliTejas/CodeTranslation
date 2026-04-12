#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int c = 0;
    while (true) {
        if (z * (c + 1) + y * c < x) c++;
        else if (z * (c + 1) + y * c > x) {
            c--;
            break;
        }
        else break;
    }
    cout << c << endl;
}