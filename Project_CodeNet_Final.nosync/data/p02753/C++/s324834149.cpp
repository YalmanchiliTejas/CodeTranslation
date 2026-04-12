#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    if(S.find('A') == string::npos || S.find('B') == string::npos) {
        cout << "No" << endl;
    } else {
        cout << "Yes" <<endl;
    }

    return 0;
}