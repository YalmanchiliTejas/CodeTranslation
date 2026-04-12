#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    char a[100][100];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> a[i][j];
        }
    }
    bool used_row[100], used_column[100];
    for(int i=0; i< max(H,W); i++){
        used_row[i]=false; used_column[i]=false;
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a[i][j]=='#') {
                used_row[i]=true; used_column[j]=true;
            }
        }
    }
    vector<int> row, column;
    for(int i=0; i<H; i++){
        if(used_row[i]) row.push_back(i);
    }
    for(int i=0; i<W; i++){
        if(used_column[i]) column.push_back(i);
    }
    for(auto x : row){
        for(auto y : column){
            cout << a[x][y];
        }
        cout << endl;
    }
}