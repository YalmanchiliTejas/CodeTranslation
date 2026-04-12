#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
        int H, W;
        vector<string> M;
        cin >> H >> W;
        vector<bool> is_del(W, true);
        for(int i = 0; i < H; i++) {
                string str;
                cin >> str;
                for(int j = 0; j < W; j++) if(str[j] == '#') is_del[j] = false;
                for(int j = 0; j < str.size(); j++) if(str[j] == '#') {
                        M.push_back(str);
                        break;
                }
        }

        for(int i = 0; i < M.size(); i++) {
                for(int j = 0; j < W; j++) if(is_del[j] == false) cout << M[i][j];
                cout << endl;
        }
        return 0;
}