#include <iostream>
using namespace std;

int main(void) {
    int x[3];
    cin >> x[0] >> x[1] >> x[2];

    int a = x[0] * 100 + x[1] * 10 + x[2];

    cout << (a % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}
