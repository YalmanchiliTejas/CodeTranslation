#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> lines(h);

    string s;
    int cnt = 0;
    for (int hi = 0; hi < h; hi++) {
        cin >> s;
        if (s.find("#") != string::npos) {
            lines.at(cnt) = s;
            cnt++;
        }
    }

    for (int i = w-1; i > -1; i--) {
        string tmp = "";
        for (int j = 0; j < cnt; j++) {
            tmp += lines.at(j).at(i);
        }

        if (tmp.find("#") == string::npos) {
            for (int j = 0; j < cnt; j++) {
                lines.at(j).erase(i, 1);
                // cout << "erased: " << lines.at(j) << endl;
            }
        }

    }

    int i = 0;
    while (i < cnt) {
        cout << lines.at(i) << endl;
        i++;
    }
}
