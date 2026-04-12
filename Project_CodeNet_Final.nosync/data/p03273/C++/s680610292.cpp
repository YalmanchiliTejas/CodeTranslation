#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> v;

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        string str;
        cin >> str;

        bool flg = false;
        for (auto c : str) {
            if (c == '#') {
                flg = true;
                break;
            }
        }
        if (flg) {
            v.push_back(str);
        }
    }

    vector<vector<char> > v2(v.size());
    for (int i = 0; i < W; i++) {
        bool flg = false;
        for (int j = 0; j < v.size(); j++) {
            if (v[j][i] == '#') {
                flg = true;
                break;
            }
        }
        if (flg) {
            for (int j = 0; j < v.size(); j++) {
                v2[j].push_back(v[j][i]);
            }
        }
    }

    for (auto a : v2) {
        for (auto b : a) {
            cout << b;
        }
        cout << endl;
    }
}