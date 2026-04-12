#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> vec(h);

    // 入力
    for (int i = 0; i < h; i++) {
        cin >> vec.at(i);
    }

    // 横の確認
    vector<int> index_h;
    for (int i = 0; i < h; i++) {
        if (vec.at(i).find('#') != string::npos) {
            index_h.push_back(i);
        }
    }

    // 縦の確認
    vector<int> index_w;
    for (int i = 0; i < w; i++) {
        bool flag = false;
        for (int j = 0; j < h; j++) {
            if (vec.at(j).at(i) == '#') flag = true;
        }
        if (flag) index_w.push_back(i);
    }

    for (auto i : index_h) {
        for (auto j : index_w) {
            cout << vec.at(i).at(j);
        }
        cout << endl;
    }
}
