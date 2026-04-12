#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string rightc = "yuiophjklnm";

    while (1) {
        string s;
        cin >> s;

        if (s == "#") break;

        
        bool pright = count(rightc.begin(), rightc.end(), s[0]);

        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            bool right = count(rightc.begin(), rightc.end(), s[i]);
            if (pright != right) {
                ans++;
                pright = right;
            }
        }

        cout << ans << endl;
    }
}