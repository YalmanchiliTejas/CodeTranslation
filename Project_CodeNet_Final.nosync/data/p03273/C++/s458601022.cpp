#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> t(h, vector<char>(w));
    int i,j;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin >> t[i][j];
        }
    }
    vector<bool> row(h);
    vector<bool> col(w);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(t[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(i=0;i<h;i++){
        if(row[i]){
            for(j=0;j<w;j++){
                if(col[j]){
                    cout << t[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}