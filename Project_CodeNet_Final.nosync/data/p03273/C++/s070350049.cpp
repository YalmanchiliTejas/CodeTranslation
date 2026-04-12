#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SORT(i) sort((i).begin(), (i).end())
#define INF 2000000000
constexpr ll mod = 1e9 + 7;
 
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> trout(H, vector<char>(W));
    vector<int> width(W,0);
    vector<int> height(H,0);
    for (int i = 0; i < H;++i){
        for (int j = 0; j < W;++j){
            cin >> trout[i][j];
        }
    }
    for (int i = 0; i < H;++i){
        int a = 0;
        for (int j = 0; j < W;++j){
            if(trout[i][j]=='.'){
                ++a;
            }
        }
        if(a != W){
            ++height[i];
        }
    }

    for (int i = 0; i < W;++i){
        int b = 0;
        for (int j = 0; j < H;++j){
            if(trout[j][i] == '.'){
                ++b;
            }
        }
        if(b != H){
            ++width[i];
        }
    }

        for (int i = 0; i < H; ++i){
            if (!height[i]) continue;
            for (int j = 0; j < W; ++j){
                if(j == W-1){
                    if(width[j]){
                        cout << trout[i][j] << "\n";
                    }
                    else {
                        cout << "\n";
                        continue;
                    }
                }
                else {
                    if(width[j]){
                        cout << trout[i][j];
                    }
                    else {
                        continue;
                    }
                }
            }
        }

    return 0;
}