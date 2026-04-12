#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string v = "aeiou";
    char c;
    cin >> c;
    cout << (count(v.begin(), v.end(), c) ? "vowel" : "consonant") << endl;
    return 0;
}
