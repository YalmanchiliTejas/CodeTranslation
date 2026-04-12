#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int h,w;
char field[101][101];

bool row[101];
bool col[101];



int main() {
    cin >> h >> w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> field[i][j];
        }
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(field[i][j]=='#'){
                row[i] = 1;
            }
        }
    }

    for(int i=0;i<w;++i){
        for(int j=0;j<h;++j){
            if(field[j][i]=='#'){
                col[i] = 1;
            }
        }
    }

    // for(int i=0;i<h;i++){
    //     cout << row[i];
    // }    
    // cout << endl;
    // for(int i=0;i<w;i++){
    //     cout << col[i];
    // }    
    
    // cout << endl;

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(row[i]==1&&col[j]==1){
                cout << field[i][j];
            }
            if(j==w-1&&row[i]==1)cout << endl;
        }
    }

    return 0;
}

