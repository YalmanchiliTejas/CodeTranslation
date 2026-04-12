#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[]) {
        int n;
        vector<string> s;
        cin >> n;
        s = vector<string>(n);
        for (auto i = 0; i < s.size(); ++i) {
                cin >> s[i];
        }
        for (int i = 1; i < s.size(); ++i) {
                if (s[i].size() < s[0].size()) {
                        swap(s[i], s[0]);
                }
        }
        sort(s[0].begin(), s[0].end());
        string ans;
        for (int i = 0; i < s[0].size(); i++) {
                bool flag {true};
                for (int j = 1; j < s.size(); j++) {
                        auto it = find(s[j].begin(), s[j].end(), s[0][i]);
                        if (it != s[j].end()) {
                                s[j].erase(it);
                        }
                        else {
                                flag = false;
                                j = s.size();
                        }
                }
                if (flag) {
                        ans.push_back(s[0][i]);
                }
        }
        cout << ans << endl;
}