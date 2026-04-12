#include <iostream>

using namespace std;

int main() {
    int r,g,b;

    cin >> r >> g >> b;
    int total = r*100 + g*10 + b;
    int mod = total % 4;
    string ans;
    if (mod == 0) {
        ans = "YES";
    } else {
        ans = "NO";
    }

    cout << ans << endl;

    return 0;
}