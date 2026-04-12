#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int64_t dp[500][210][210] = {};
int dj[4] = {1, 1, 0, 0};
int dk[4] = {0, 1, 0, 1};

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<int>> a(H, vector<int>(W));
    for(auto& c : a) for(auto & i : c){
        cin >> i;
    }

    dp[0][0][0] = a[0][0];
    for(int i = 0; i < H + W; ++i){
        for(int j = 0; j <= min(i, W-1); ++j){
            for(int k = 0; k <= min(i, W-1); ++k){
                for(int l = 0; l < 4; ++l){
                    int nj = j + dj[l];
                    int nk = k + dk[l];
                    if(nj >= W || nk >= W || (i+1-nj) >= H || (i+1-nk) >= H) continue;
                    if(nk == nj){
                        dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k] + a[i-nj+1][nj]);
                    } else {
                        dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k] + a[i-nj+1][nj] + a[i-nk+1][nk]);
                    }
                }
            }
        }
    }
    cout << dp[H+W-2][W-1][W-1] << endl;
}