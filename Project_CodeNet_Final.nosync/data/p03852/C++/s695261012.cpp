#include <iostream>
using namespace std;

int main() {
    char list[] = {'a','e','i','o','u'};
    char c;
    cin >> c;
    for(int i = 0;i < 5;i++) {
        if(list[i] == c) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}