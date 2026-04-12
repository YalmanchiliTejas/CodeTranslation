#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char c = s.at(0);
    if (c != s.at(1) || c != s.at(2)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}