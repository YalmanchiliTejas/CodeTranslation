#include <iostream>
#include <string>
#include <set>

using namespace std;

#define L 0
#define R 1


int count(string s) {
    string left = "qwertasdfgzxcvb";
    string right = "yuiophjklnm";
    int c = 0;
    int cur_hand;
    if (left.find(s[0], 0) != string::npos) cur_hand = L;
    else cur_hand = R;
    for (string::iterator si = s.begin() + 1; si != s.end(); si++) {
        if (left.find(*si, 0) != string::npos) {
            if (cur_hand == R) {
                cur_hand = L;
                c++;
//                cout << "Changed: " << *si << "\n";
            }
        } else {
            if (cur_hand == L) {
                cur_hand = R;
                c++;
//                cout << "Changed: " << *si << "\n";
            }
        }
    }
    return c;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "#") break;
        cout << count(s) << endl;
    }
    return 0;
}