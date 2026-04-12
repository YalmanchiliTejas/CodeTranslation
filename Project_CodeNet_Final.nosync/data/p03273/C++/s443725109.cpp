#include <bits/stdc++.h>
using namespace std;
int main () {
    int h, w;
    cin >> h >> w;
    vector<string> v;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        bool flag = false;
        for (auto x: s) {
            if (x != '.') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            v.push_back(s);
        }
    }
    set<int> l;
    for (int j = 0; j < w; j++) {
        bool flag = 1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i][j] != '.') {
                flag = 0;
                break;
            }
        }
        if (flag) {
            l.insert(j);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < w; j++) {
            if (l.find(j) == l.end()) {
                cout << v[i][j];
            }
        }
        cout << endl;
    }
}