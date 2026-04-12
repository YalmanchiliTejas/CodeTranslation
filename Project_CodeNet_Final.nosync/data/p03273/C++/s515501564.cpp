#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for(int i=0; i < H; i++) {
        for(int j=0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    // 横の揃っているの削除
    for(int i=0; i < a.size(); i++) {
        bool flag = true;
        for(int j=0; j < a[i].size(); j++) if(a[i][j] == '#') flag = false;
        if(flag) {
            a.erase(a.begin() + i);
            i--;
        }
    }

    // 縦の揃っているの削除
    for(int j=0; j < a[0].size(); j++) {
        bool flag = true;
        for(int i=0; i < a.size(); i++) if(a[i][j] == '#') flag = false;
        if(flag) {
            for(int i=0; i < a.size(); i++) a[i].erase(a[i].begin() + j);
            j--;
        }
    }

    for(int i=0; i < a.size(); i++) {
        for(int j=0; j < a[i].size(); j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}

