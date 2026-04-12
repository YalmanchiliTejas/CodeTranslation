#include <iostream>
using namespace std;

int main(void) {
    int x;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> x;
    cout << (x == 7 || x == 5 || x == 3? "YES" : "NO") << "\n";
    return 0;
}