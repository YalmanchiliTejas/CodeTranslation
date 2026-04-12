#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'A') {
            a = true;
        }
        else {
            b = true;
        }
    }
    if(a == true && b == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}