#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, h, t = -1, c = 0;
    cin >> N;
    for (; N > 0; N--) {
        cin >> h;
        if (h >= t) {
            c++;
            t = h;
        }
    }

    cout << c << endl;
    return 0;

}