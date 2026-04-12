/**
 *      ABC 107 B
 *      author  : kyomukyomupurin
 *      created : 2018/08/29
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W; cin >> H >> W;
    vector<vector<char> > v(H, vector<char>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c; cin >> c;
            v[i][j] = c;
        }
    }

    /*for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << v[i][j];
        }
        cout << '\n';
    }*/

    vector<int> w;
    vector<int> h;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (v[i][j] == '#'){
                w.push_back(i);
            }
        }
    }

    for (int j = 0; j < W; ++j) {
        for (int i = 0; i < H; ++i) {
            if (v[i][j] == '#'){
                h.push_back(j);
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (find(w.begin(), w.end(), i) != w.end() && find(h.begin(), h.end(), j) != h.end()){
                cout << v[i][j];             
            }         
        }
        if (find(w.begin(), w.end(), i) != w.end()){
            cout << '\n';
        }
    }

    return 0;
}