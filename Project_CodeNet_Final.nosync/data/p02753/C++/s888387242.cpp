#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    if (S[0] == S[1] && S[0] == S[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}