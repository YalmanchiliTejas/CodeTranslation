#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
int H, W, p = 0;
cin >> H >> W;
string s;

vector<string> a(H);
for (int i = 0; i < H; ++i) {
        cin >> s;
        if (s.find('#') != -1) {
                a[p] = s;
                p++;
        }   
}

for (int i = 0; i < W; ++i) {
        bool flag = false;
        if (a[0][i] == '.') {
                flag = true;
                for (string j : a) {
                        if (j[i] == '#') {
                                flag = false;
                                break;
                        }   
                }   
        }   
        if (flag) {
                for (int k = 0; k < a.size(); ++k) {
                        a[k][i] = '_';
                }   
        }   
}

for (string i : a) {
        for (char j : i) {
                if (j == '_') { 
                        continue;
                }   
                cout << j;
        }   
        cout << endl;
}
}