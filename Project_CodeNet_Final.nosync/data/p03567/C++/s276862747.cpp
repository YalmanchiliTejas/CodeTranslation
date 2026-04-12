#include <iostream>
using namespace std;

int main() {
    // input
    string S;
    cin >> S;

    // solve & output
    cout << ((int)S.find("AC") != -1 ? "Yes" : "No") << endl;

    return 0;
}
