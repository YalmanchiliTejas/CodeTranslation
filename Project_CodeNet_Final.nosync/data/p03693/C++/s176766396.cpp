#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, g, b;

int main() {
    cin >> r >> g >> b;

    int check = r*100 + g*10 + b;
    if (check % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
