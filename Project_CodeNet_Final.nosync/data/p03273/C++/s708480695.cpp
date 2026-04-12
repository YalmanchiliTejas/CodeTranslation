#include<bits/stdc++.h>

using namespace std;

int main()
{
    int H,W;
    cin >> H >> W;
    char a[100][100];
    bool isSharpRow[100];
    bool isSharpCol[100];

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                isSharpRow[i] = true;
                isSharpCol[j] = true;
            }
        }
    }

    for(int i = 0; i < H; ++i){
        if(isSharpRow[i] == false) continue;
        for(int j = 0; j < W; ++j){
            if(isSharpCol[j] == true) cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}

