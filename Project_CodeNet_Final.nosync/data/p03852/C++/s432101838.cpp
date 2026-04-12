#include <iostream>
using namespace std;
int main() {
    char c;
    cin >> c;
    if ((c == 'a') || (c == 'u') || (c == 'i') || (c == 'o') || (c == 'e'))
        cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}