#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void erasedot(vector<vector<char> > &m, int &H, int &W) {
    for(int i = 0; i < H; i++) {
        bool check = 1;
        for(int j = 0; j < W; j++) {
            if(m.at(i).at(j) == '#') {
                check = 0;
                break;
            }
        }
        if(check) {
            m.erase(m.begin() + i);
            i--;
            H--;
        }
    }
    return;
}
void changehw(vector<vector<char> > &m, int &H, int &W) {
    vector<vector<char> > tempm(W, vector<char>(H));
    int tempH = H, tempW = W;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            tempm.at(j).at(i) = m.at(i).at(j);
        }
    }
    H = tempW;
    W = tempH;
    m = tempm;

    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char> > m(H,vector<char>(W));

    for(int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < W; j++) {
            m.at(i).at(j) = S.at(j);
        }
    }
    erasedot(m, H, W);
    changehw(m, H, W);
    erasedot(m, H, W);
    changehw(m, H, W);
    

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << m.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}