#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, bool> m;
    string l = "qwertasdfgzxcvb";
    string r = "yuiophjklnm";
    for (auto&& i : l) {
        m[i] = false;
    }
    for (auto&& i : r) {
        m[i] = true;
    }
    while (true) {
        string s;
        cin >> s;
        if (s == "#") {
            return 0;
        }

        bool state = m[s[0]];
        int count = 0;
        for (int i = 1; i < s.size(); ++i) {
            bool newState = m[s[i]];
            if (state != newState) {
                state = newState;
                count += 1;
            }
        }
        cout << count << endl;
    }
}