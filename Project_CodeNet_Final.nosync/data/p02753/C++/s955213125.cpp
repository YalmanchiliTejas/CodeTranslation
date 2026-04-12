#include <iostream>
using namespace std;

char s[10] = {};

int main(){
    cin >> s;

    if (s[0] == s[1] && s[0] == s[2]) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }

    return 0;
}
