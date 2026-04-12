#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char c;
    cin >> c;
    string str = "aiueo";
    if (count(str.begin(), str.end(), c) > 0) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}
