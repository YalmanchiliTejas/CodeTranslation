#include <iostream>
using namespace std;
int main() {
    char c;
    cin >> c;
    for (auto d : {'a','e','i','o','u'}){
        if (c == d){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}