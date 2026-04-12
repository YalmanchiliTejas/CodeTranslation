#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    string S;
    cin >> S;
    if(S == "AAA" || S == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
