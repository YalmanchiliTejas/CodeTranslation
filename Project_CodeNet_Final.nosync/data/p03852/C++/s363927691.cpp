#include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<char> vowels = {'a', 'i', 'u', 'e', 'o'};
    char in('\0');
    cin >> in;

    bool flag(false);
    for(int i(0); i < vowels.size(); ++i) {
        if(in == vowels.at(i)) {
            flag = true;
            break;
        }
    }

    if(flag) cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
}