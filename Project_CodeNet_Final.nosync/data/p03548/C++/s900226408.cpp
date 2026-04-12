#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int X, Y, Z;
    cin >> X;
    cin >> Y;
    cin >> Z;
    int cnt = 0;
    for(int i = 1; i < 10e5; i++) {
        if (X >= Y * i + Z * (i + 1))
            cnt++;
        else
            break;
    }
    cout << cnt << endl;
    return 0;
}