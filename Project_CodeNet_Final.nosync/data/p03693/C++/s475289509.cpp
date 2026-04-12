#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int x = r * 100 + g * 10 + b;
    cout << (x % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}