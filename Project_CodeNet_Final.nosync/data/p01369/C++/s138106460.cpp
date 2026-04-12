#include <iostream>
#include <string>

using namespace std;

const string keys = "qwertasdfgzxcvb";

int main() {
    for (;;) {
        string s;
        cin >> s;
        if (s == "#") break;

        int res = 0;
        bool cur = keys.find(s.substr(0, 1)) != string::npos;
        for (int i = 1; i < s.size(); i++) {
            bool prev = cur;
            cur = keys.find(s.substr(i, 1)) != string::npos;
            if (cur != prev) {
                res++;
            }

        }

        cout << res << endl;
    }
}