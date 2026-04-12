#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int h, w;
    cin >> h >> w;

    char mat[100][100];
    rep(i, h){
        rep(j, w){
            cin >> mat[i][j];
        }
    }

    bool row[100] = {false}, column[100] = {false};

    rep(i, h){
        rep(j, w){
            if(mat[i][j] != '.' && !row[i]){
                row[i] = true;
            }
        }
    }
    rep(i, w){
        rep(j, h){
            if(mat[j][i] != '.' && !column[i]){
                column[i] = true;
            }
        }
    }

    rep(i, h){
        rep(j, w){
            if(row[i] && column[j]){
                cout << mat[i][j];
            }
        }
        cout << '\n';
    } 

    return 0;
}