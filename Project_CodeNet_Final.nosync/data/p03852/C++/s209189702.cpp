#include <iostream>
using namespace std;
int main() {
    char asd;
    cin >> asd;
    if (asd == 'a' || asd == 'e' || asd == 'u' || asd == 'o' || asd == 'i') {
        cout << "vowel" << endl;
    }
    else cout << "consonant" << endl;
    return 0;
}