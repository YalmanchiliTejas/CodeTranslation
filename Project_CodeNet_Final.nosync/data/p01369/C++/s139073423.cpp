#include <iostream>
#include <string>

using namespace std;

int c(char t){
    if (t=='y'||t=='u'||t=='i'||t=='o'||t=='p'||t=='h'||t=='j'||t=='k'||t=='l'||t=='n'||t=='m') {
        return 1;
    }
    return 0;
}

int main() {
    string s;
    while (cin >> s) {
        if (s[0] == '#') { break; }

        int now = c(s[0]);
        int ans = 0;

        for (int i = 1; s[i] != '\0'; i++){
            int p = c(s[i]);
            if (now != p) { ans++; }
            now = p;
        }
        cout << ans << endl;
    }
    return 0;
}
