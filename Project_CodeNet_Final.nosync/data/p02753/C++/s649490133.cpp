#include <iostream>
using namespace std;

int main() {
    char s[4]; cin >> s;
    int a = 0, b = 0;
    for (auto c : s) {
        a += c == 'A';
        b += c == 'B';
    }
    cout << (a != 3 && b != 3 ? "Yes" : "No") << endl;
}

