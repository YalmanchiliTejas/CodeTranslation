#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    char c;
    cin >> c;
    char vowels[6] = "aiueo";
    for (int i(0); i < 6; i++){
        if (c == vowels[i]){
            cout << "vowel";
            return 0;
        }
    }
    cout << "consonant";
    return 0;
} 