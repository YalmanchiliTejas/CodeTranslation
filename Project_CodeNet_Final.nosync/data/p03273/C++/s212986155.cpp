#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<bool> column(h, false), row(w, false);
    vector<vector<char>> field(h, vector<char>(w));
    rep(i, h) {
        string temp;
        cin >> temp;
        rep(j, w) {
            field.at(i).at(j) = temp.at(j);
            if(temp.at(j) == '#') {
                column.at(i) = true;
                row.at(j) = true;
            }
        }
    }
    rep(i, h) {
        if(!column.at(i)) continue;
        rep(j, w) if(row.at(j)) cout << field.at(i).at(j);
        cout << endl;
    }
}