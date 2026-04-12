#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    char c;
    cin >> c;

    cout << (string("aiueo").find(c) != string::npos ? "vowel" : "consonant") << endl;

    return 0;
}
