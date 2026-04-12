#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    for (int i=0; i<h; i++){
        cin >> grid[i];
    }
    
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (grid[i][j]=='#'){
                row[i] = true; col[j] = true;
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if (row[i] and col[j]){
                cout << grid[i][j];
            }
        }
        if (row[i]) cout << endl;
    }
}