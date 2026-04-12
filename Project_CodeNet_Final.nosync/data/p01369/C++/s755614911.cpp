#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string t = "yuiophjklnm";
    while (cin >> s, s != "#") {
        int count = 0;
        bool p = (t.find(s[0]) == string::npos);
        for (int i = 1; i < s.size(); i++) {
            if ((t.find(s[i]) == string::npos) != p) {
                count++;
                p = (t.find(s[i]) == string::npos);
            }
        }
        cout << count << endl;
    }
    
    return 0;
}

