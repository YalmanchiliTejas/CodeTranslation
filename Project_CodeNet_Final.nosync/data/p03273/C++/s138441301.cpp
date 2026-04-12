#include <iostream>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    char f[H][W];

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> f[i][j];
            //cout << f[i][j];
        }
        //cout << endl;
    }

    bool bH[H], bW[W];
    for(int i = 0; i < H; i++) {
        bool b = true;
        for(int j = 0; j < W; j++) {
            b &= (f[i][j] == '.');
        }
        bH[i] = !b;
    }
    for(int j = 0; j < W; j++) {
        bool b = true;
        for(int i = 0; i < H; i++) {
            b &= (f[i][j] == '.');
        }
        bW[j] = !b;
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(bH[i] && bW[j]) {
                cout << f[i][j];
            }
        }
        if(bH[i]) {
            cout << endl;
        }
    }


    return 0;
}