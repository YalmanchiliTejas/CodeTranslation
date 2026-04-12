#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int H,W;
    cin>>H>>W;
    char map[H][W];
    unordered_map<int, int> mp_col;
    unordered_map<int, int> mp_row;

    for(int col=0; col<H; col++) {
        int count_col=0;
        for (int row = 0; row < W; row++) {
            cin >> map[col][row];
            if(map[col][row]=='.'){
                count_col++;
            }
        }
        if(count_col==W){
            mp_col[col]=1;
        }
    }

    for(int row=0; row<W; row++) {
        int count_row=0;
        for (int col = 0; col < H; col++) {
            if(map[col][row]=='.'){
                count_row++;
            }
        }
        if(count_row==H){
            mp_row[row]=1;
        }
    }

    for(int col=0; col<H; col++) {
        for (int row = 0; row < W; row++) {
            if(mp_col[col]!=1 and mp_row[row]!=1) {
                cout << map[col][row];
            }
        }
        if(mp_col[col]!=1)
            cout<<endl;
    }

    return 0;

}