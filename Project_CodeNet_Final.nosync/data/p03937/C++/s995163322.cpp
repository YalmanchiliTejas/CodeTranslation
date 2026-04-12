#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int H, W;
    cin >> H >> W;
    int count = 0;
    vector<vector<char>> Aij(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            char tmp;
            cin >> tmp;
            Aij[i][j] = tmp;
            if(tmp=='#'){count++;}
        }
    }

    typedef tuple<int, int, int> XY;
    queue<XY> que;
    que.push(XY(0,0,1));

    int dxl[2] = {1, 0};
    int dyl[2] = {0, 1};

    while(!que.empty()){
        XY coords = que.front(); que.pop();
        int x = get<0>(coords);
        int y = get<1>(coords);
        int tmpCount = get<2>(coords);

        if( x+1==W && y+1==H && tmpCount==count){
            cout << "Possible" << endl;
            return 0;
        }

        for(int i=0; i<2; i++){
            int dx = dxl[i];
            int dy = dyl[i];
            
            if(y+dy < H && x+dx < W && Aij[y+dy][x+dx] == '#'){
                que.push(XY(x+dx, y+dy, tmpCount+1));
            }
        }
    }

    cout << "Impossible" << endl;
    return 0;
    
}