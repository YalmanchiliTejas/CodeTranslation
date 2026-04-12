#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int H, W;
    cin >> H >> W;
    char a[H][W];
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }

    //判定用
    vector<bool> row(H, false);
    vector<bool> col(W, false);

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++){
        if (row[i]){
            for (int j = 0; j < W; j++){
                if (col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}