#include <iostream>
using namespace std;

int main() {
    char str;
    cin >> str;
    if(str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}
