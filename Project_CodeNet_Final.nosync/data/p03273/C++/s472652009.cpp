#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            cin >> a[y][x];
        }
    }
    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for (int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            if(a[y][x]=='#'){
                row[y] = true;
                col[x] = true;
            }
        }
    }

    for (int y=0; y<H; y++){
        if(row[y]){
            for(int x=0; x<W; x++){
                if(col[x]){
                    cout << a[y][x];
                }
            }
            cout << endl;
        }
    }
}