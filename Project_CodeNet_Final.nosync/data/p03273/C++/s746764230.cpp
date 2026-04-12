#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<bool> column(h, false), row(w, false);
    vector<vector<char>> field(h, vector<char>(w));
    rep(i, h) {
        string str;
        cin >> str;
        rep(j, w) {
            field.at(i).at(j) = str.at(j);
            if(str.at(j) == '#') {
                column.at(i) = true;
                row.at(j) = true;
            }
        }
    }
    rep(i, h) {
        rep(j, w) if(column.at(i) && row.at(j)) cout << field.at(i).at(j);
        if(column.at(i)) cout << endl;
    }
    
}