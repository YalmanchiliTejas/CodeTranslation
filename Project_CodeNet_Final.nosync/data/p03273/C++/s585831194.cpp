#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> v= vector<vector<char>>(h, vector<char>(w, '.'));
    vector<vector<bool>> b= vector<vector<bool>>(h, vector<bool>(w, true));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> v[i][j];
        }
    }
    vector<bool> checkerw(w);
    int c;
    for(int i = 0; i < h; i++){
        for(int k = 0; k < w; k++){
            checkerw[k] = false;
        }
        c = 0;
        for(int j = 0; j < w; j++){
            if(v[i][j] == '.') checkerw[j] = true;
        }
        for(int l = 0; l < w; l++){
            if(checkerw[l]) c++;
        }
        if(c == w){
            for(int m = 0; m < w; m++){
                b[i][m] = false;
            }
        }
    }
    vector<bool> checkerh(h);
    for(int i = 0; i < w; i++){
        for(int k = 0; k < h; k++){
            checkerw[k] = false;
        }
        c = 0;
        for(int j = 0; j < h; j++){
            if(v[j][i] == '.') checkerw[j] = true;
        }
        for(int l = 0; l < h; l++){
            if(checkerw[l]) c++;
        }
        if(c == h){
            for(int m = 0; m < h; m++){
                b[m][i] = false;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(b[i][j]) cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}
