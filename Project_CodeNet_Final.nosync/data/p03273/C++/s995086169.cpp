#include "bits/stdc++.h"
using namespace std;
int INF = numeric_limits<int>::max() / 2;
using ll = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    char map[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i][j];
        }
    }

    vector<bool> hb(h,false), wb(w,false);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(map[i][j] == '#'){
                hb[i] = true;
                wb[j] = true;
            } 
        }
    }

    for(int i = 0; i < h; i++){
        if(hb[i]){
            for(int j = 0; j < w; j++){
                if(wb[j]) cout << map[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}