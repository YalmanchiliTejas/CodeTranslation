#include <iostream>
#include <vector>
#include <string>

#define REP(i,n) for(int i = 0;i < n;i++)

using namespace std;

typedef pair<int,int> P;
#define P_NUM 4


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H,W;

    cin >> H >> W;

    vector<string> grid;
    int h_tmp = H;
    REP(i,H){
        string hoge = "";
        cin >> hoge;
        if(hoge.find('#') != string::npos)
            grid.push_back(hoge);
        else h_tmp--;
    }
    H = h_tmp;

    bool flag[W];

    REP(c,W)
        flag[c] = false;

    REP(c,W){
        REP(r,H){
            if(grid[r][c] == '.')
                flag[c] = false || flag[c];
            else flag[c] = true;
        }
    }

    REP(r,H){
        REP(c,W) {
            if(flag[c])
                cout << grid[r][c];
        }
        cout << endl;
    }

    return 0;
}