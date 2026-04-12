#include <iostream>
using namespace std;

int main(void) {
    int n;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cout << n * 800 - (n / 15) * 200 << "\n";
    return 0;
}