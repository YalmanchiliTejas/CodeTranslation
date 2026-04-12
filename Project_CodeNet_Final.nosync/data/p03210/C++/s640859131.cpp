#include <iostream>

using namespace std;

int main() {
    int X, myNum[] = {7, 5, 3};
    bool celebra = false;

    cin >> X;

    for(int i = 0; i < 3; i++) {

        if(X == myNum[i]) {
            cout << "YES" << endl;

            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}