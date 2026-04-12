
#include <iostream>

using namespace std;

int main()
{
    char c;
    bool a = false, b = false;

    while ((cin >> c)) {
        if (c == 'A') {
            a = true;
        }
        if (c == 'B') {
            b = true;
        }
    }
    if (a && b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
