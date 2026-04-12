#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string c;
    cin >> c;
    
    if (c == "a" || c == "i" || c == "u" || c == "e" || c == "o") {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    
    return 0;
}