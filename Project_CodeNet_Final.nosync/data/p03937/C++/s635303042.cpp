#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    int H, W;
    cin >> H >> W;
    vector<string> grid(H + 2);
    string empty_row;
    for(int i = 0; i < W + 2; i++){
        empty_row.push_back('.');
    }
    grid[0] = grid[H + 1] = empty_row;

    for(int i = 0; i < H; i++){
        string row = ".";
        for(int j = 0; j < W; j++){
            char ipt;
            cin >> ipt;
            row.push_back(ipt);
        }
        row.push_back('.');
        grid[i + 1] = row;
    }

//    for(auto row: grid){
//        for(char c: row){
//            cout << c;
//        }
//        cout << endl;
//    }


    for(int i = 1; i < H + 2; i++){
        for(int j = 1; j < W + 2; j++){
            int cnt = 0;
            if(grid[i][j] != '#') continue;
            int x[4] = {-1, 0,  0, 1};
            int y[4] = { 0, 1, -1, 0};
            for(int k = 0; k < 4; k++){
                if(grid[i + y[k]][j + x[k]] == '#'){
                    cnt++;
                    if(i == 1 && j == 1 && cnt >= 2){
                        cout << "Impossible" << endl;
                        return 0;
                    }
                    if(cnt >= 3){
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            }
            if(grid[i - 1][j] == '#' && grid[i][j - 1] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}
