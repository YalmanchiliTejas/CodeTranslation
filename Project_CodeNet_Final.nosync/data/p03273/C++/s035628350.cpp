#include <bits/stdc++.h>
using namespace std;

void solve(int H, int W, std::vector<std::string> a){
    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i = 0; i < H; ++i){
        if(row[i]){
            for(int j = 0; j < W; ++j){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<std::string> a;
    std::string s;
    for(int h = 0; h < H; ++h){
        cin >> s; a.push_back(s);
    }
    solve(H, W, std::move(a));
    return 0;
}
