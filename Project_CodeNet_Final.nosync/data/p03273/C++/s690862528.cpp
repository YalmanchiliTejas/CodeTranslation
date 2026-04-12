#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    string s[H];
    int output_row = 0;
    int output_col = 0;
    int output_rows[H];
    int output_cols[W];
    for(int i = 0; i < H; i++){
        cin >> s[i];
        output_rows[i] = 0;
    }
    for(int i = 0; i < W; i++){
        output_cols[i] = 0;
    }
    // check row;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i][j] == '#'){
                output_rows[i] = 1;
                output_cols[j] = 1;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(output_rows[i] == 1 && output_cols[j] == 1){
                cout << s[i][j];
            }
        }
        if(output_rows[i] == 1){
            cout << endl;
        }
    }
    return 0;
}