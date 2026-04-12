#include <iostream>
#include <set>
using namespace std;

int main(void) {
    set<char> left, right;
    string up = "qwertyuiop", mid = "asdfghjkl", down = "zxcvbnm";
    for (int i = 0; i < 5; i++) {
        left.insert(up[i]);
        left.insert(mid[i]);
        left.insert(down[i]);
    }
    for (int i = 5; i < up.size(); i++) right.insert(up[i]);
    for (int i = 5; i < mid.size(); i++) right.insert(mid[i]);
    for (int i = 5; i < down.size(); i++) right.insert(down[i]);

    string s;
    while (cin >> s, s != "#") {
        char which;
        if (left.find(s[0]) != left.end()) {
            which = 'l';
        } else {
            which = 'r';
        }

        int cnt = 0;
        for (int i = 1; i < s.size(); i++) {
            if (which == 'l') {
                if (left.find(s[i]) == left.end()) {
                    which = 'r';
                    cnt++;
                }
            } else {
                if (right.find(s[i]) == right.end()) {
                    which = 'l';
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}