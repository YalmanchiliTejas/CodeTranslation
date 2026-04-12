#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, W;
    array<array<char, 100>, 100> a;
    array<int, 100> row, column;
    for(auto &num:row){
        num = 0;
    }
    for(auto &num:column){
        num = 0;
    }
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a.at(i).at(j);
            if(a.at(i).at(j) == '#'){
                row.at(i)++;
                column.at(j)++;
            }
        }
    }
    for (int i = 0; i < H; ++i) {
        if(row.at(i) == 0){
            continue;
        }
        for (int j = 0; j < W; ++j) {
            if(column.at(j) == 0){
                continue;
            }
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}
