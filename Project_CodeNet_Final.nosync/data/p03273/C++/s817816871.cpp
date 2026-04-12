#include <bits/stdc++.h>

using namespace std;
#define lint long long
#define P pair<int, int>

int main() {
    int H, W;
    cin >> H >> W;
    
    char a[H][W];
    
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> a[i][j];
        }
    }
    
    vector<int> r,c;
    
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(a[i][j] == '#'){
                r.push_back(i);
                break;
            }
        }
    }
    
    for(int i = 0; i < W; ++i){
        for(int j = 0; j < H; ++j){
            if(a[j][i] == '#'){
                c.push_back(i);
                break;
            }
        }
    }
    
    for(int i = 0; i < r.size(); ++i){
        for(int j = 0; j < c.size(); ++j){
            cout << a[r[i]][c[j]];
        }
        cout << endl;
    }
}
