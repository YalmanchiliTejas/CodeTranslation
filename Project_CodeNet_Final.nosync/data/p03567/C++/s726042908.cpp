#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(void){
    string s, t;
    bool ans = false;
    cin >> s;
    t = "AC";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[0] && s[i + 1] == t[1]) ans = true;
    }
    if (ans) cout << "Yes";
    else cout << "No";
    return 0;
}
