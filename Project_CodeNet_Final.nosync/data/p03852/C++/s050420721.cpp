#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
// #include <string>
// #include <set>

using namespace std;
typedef unsigned long long ull;

int main(int argc, char const *argv[]) {
    char c;
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }

    return 0;
}
