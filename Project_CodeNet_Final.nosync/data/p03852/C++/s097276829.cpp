#include <iostream>
#include <string>

using namespace std;

int main(void) {
    char c;
    string ans;
    cin >> c;
    ans = "consonant";
    if(
        c == 'a' ||
        c == 'i' ||
        c == 'u' ||
        c == 'e' ||
        c == 'o'
    ) {
        ans = "vowel";
    }
    cout << ans << endl;
    return 0;
}



