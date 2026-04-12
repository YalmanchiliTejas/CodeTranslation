#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, M;
    cin >> H >> M;
    vector<string> a(H);
    for(int i=0; i<H; ++i) {
        cin >> a[i];
    }
    string s(M, '.');
    vector<vector<int> > con(2);
    for(int i=0; i<H; ++i) {
        if(a[i] == s) {
            con[0].push_back(i);
        }
    }
    int d=0;
    for(int i=0; i<M; ++i) {
        for(int j=0; j < H; ++j) {
            if(a[j][i] == '.') {
                ++d; 
            } 
        }
        if(d == H) {
            con[1].push_back(i);
        }
        d=0;
    }
    for(int i=0; i < H; ++i) {
        bool i_ = true;
        for(int k = 0; k<con[0].size(); ++k) {
            if(con[0][k] == i) {
                i_ = false;
                break;
            }
        }
        for(int j=0; j < M; ++j) {
            bool j_ = true;
            for(int l=0;l<con[1].size(); ++l) {
                if(con[1][l] == j) {
                    j_ = false;
                    break;
                }
            }
            if(i_ && j_) {
                cout << a[i][j];
            }
        }
        if(i_) {
            cout << endl;
        }
    }
}