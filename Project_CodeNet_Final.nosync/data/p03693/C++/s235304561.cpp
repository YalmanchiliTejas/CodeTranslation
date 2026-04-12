#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, total;
    cin >> R >> G >> B;
    total = R * 100 + G * 10 + B;
    if (total % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}