#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> mass(h);
    for (int i = 0; i < h; i++){
        cin >> mass[i];
    }

    vector<bool> row(h,false);
    vector<bool> col(w,false);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (mass[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++){
        if (row[i]){
            for (int j = 0; j < w; j++){
                if (col[j]){
                    cout << mass[i][j];
                }
            }
            cout << endl;
        }
    }
}