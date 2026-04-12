#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    for (int h = 0; h < H; ++h){
        for (int w = 0; w < W; ++w){
            cin >> A[h][w];
        }
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            if(A[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < H; ++i){
        if(row[i]){
            for (int j = 0; j < W; ++j){
                if(col[j]){
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}