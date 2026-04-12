#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int strlen = s.length();
    bool isAccepted = false;
    for (int i = 0; i < strlen - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            isAccepted = true;
        }
    }

    cout << (isAccepted ? "Yes" : "No") << "\n";

    int a;
    cin >> a;
}