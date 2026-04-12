#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));

    rep(i,H){
        rep(j,W){
            cin >> a.at(i).at(j);
        }
    }

    rep(i,H){
        // i行目はすべて白か？
        int counter_w = 0;
        rep(j,W){
            if(a.at(i).at(j) == '.'){
                counter_w++;
            }
        }
        if (counter_w == W){
            a.erase(a.begin() + i);
            H--;
            i = -1;
        }
    }

    rep(j,W){
        // j列目はすべて白か？
        int counter_w = 0;
        rep(i,H){
            if(a.at(i).at(j) == '.'){
                counter_w++;
            }
        }
        
        if (counter_w == H){
            // j列目を削除
            rep(ri,H){
                a.at(ri).erase(a.at(ri).begin() + j);
            }
            j = -1;
            W--;
        }
    }

    rep(i,H){
        rep(j,W){
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}