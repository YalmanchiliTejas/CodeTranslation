#include <iostream>
#include <vector>
using namespace std;

int main() {
    char c;
    cin >> c;
    vector <char> vowel = {'a', 'e', 'i', 'o', 'u'};
    bool flag = false;
    for (char v : vowel){
        if (c == v) {
            flag = true;
            cout << "vowel" << endl;
        }
    }
    if (flag == false) cout << "consonant" << endl;
    return 0;  
}