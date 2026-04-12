#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    A *= 100;
    B *= 10;

    if((A + B + C)%4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
