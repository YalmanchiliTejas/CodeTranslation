#include <iostream>
using namespace std;

int main(void) {
        int n, x, y;
        cin >> n;
        x = 800 * n;
        y = (n / 15) * 200;
        cout << x - y << endl;
}