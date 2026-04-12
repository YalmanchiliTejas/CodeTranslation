#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int height, width;
    cin >> height >> width;
    vector<vector<char>> cell(height, vector<char>(width));
    rep(i, 0, cell.size()){
        rep(j, 0, cell.at(0).size()){
            cin >> cell.at(i).at(j);
        }
    }
    vector<bool> rows(cell.size(), false);
    vector<bool> columns(cell.at(0).size(), false);
    rep(i, 0, cell.size()){
        rep(j, 0, cell.at(0).size()){
            if(cell.at(i).at(j) == '#'){
                rows.at(i) = true;
                columns.at(j) = true;
            }
        }
    }
    rep(i, 0, cell.size()){
        if(rows.at(i)){
            rep(j, 0, cell.at(0).size()){
                if(columns.at(j)){
                    cout << cell.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}