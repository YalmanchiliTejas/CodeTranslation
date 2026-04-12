#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    char mas[105][105];
    bool rowCheck[105], colCheck[105];

    cin >> H >> W;

    fill_n(rowCheck, 105, true);
    fill_n(colCheck, 105, true);

    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            cin >> mas[i][j];
            rowCheck[i] &= (mas[i][j] == '.');
            colCheck[j] &= (mas[i][j] == '.');
        }
    }

    for ( int i = 0; i < H; i++ ) {
        if ( !rowCheck[i] ) {
            for ( int j = 0; j < W; j++ ) {
                if ( !colCheck[j] ) {
                    cout << mas[i][j];
                }
            }
            cout << endl;
        }
    }

    return ( 0 );
}
