#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
#define int long long int
const int INF = 1001001001001001LL;
const int MOD = 1000000007;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int g[54][54];
bool used[54][54][4];
bool goal[4];
bool flag;
int h, w;

void dfs(int i, int j, int dir){
    
    int migi_i = i + di[(dir + 3) % 4];
    int migi_j = j + dj[(dir + 3) % 4];
    int mae_i = i + di[dir];
    int mae_j = j + dj[dir];
    
    /*
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    if(i == h and j == 1) goal[1] = true;
    if(i == 1 and j == w) goal[2] = true;
    if(i == h and j == w) goal[3] = true;

    int cnt = 0;
    for(int i = 1; i < 4; i++) if(goal[i]) cnt++;
    if(i == 1 and j == 1 and cnt == 3) flag = true;

    // (1) 右が空いてたら、右に曲がる
    if(g[migi_i][migi_j] == 1){
        int ni = migi_i;
        int nj = migi_j;
        int ndir = (dir + 3) % 4;
        if(!used[ni][nj][ndir]){
            used[ni][nj][ndir] = true;
            g[ni][nj] = 0;
            dfs(ni, nj, ndir);
        }
    }
    
    // (2) 右が塞がっていて、かつ、前が空いてたら、直進する
    if(g[migi_i][migi_j] == 0 and g[mae_i][mae_j] == 1){
        int ni = mae_i;
        int nj = mae_j;
        int ndir = dir;
        if(!used[ni][nj][ndir]){
            g[ni][nj] = 0;
            used[ni][nj][ndir] = true;
            dfs(ni, nj, ndir);
        }
    }
    

    // (3) 右も左も塞がっていたら、左に曲がる
    if(g[migi_i][migi_j] == 0 and g[mae_i][mae_j] == 0){
        int ni = i;
        int nj = j;
        int ndir = (dir + 1) % 4;
        if(!used[ni][nj][ndir]){
            g[ni][nj] = 0;
            used[ni][nj][ndir] = true;
            dfs(ni, nj, ndir);
        }
    }
    
    if(i == h and j == 1) goal[1] = false;
    if(i == 1 and j == w) goal[2] = false;
    if(i == h and j == w) goal[3] = false;


}

signed main(){
    
    while(1){

        cin >> h >> w;
        if(h == 0) break;
        memset(g, 0, sizeof(g));
        memset(used, false, sizeof(used));
        memset(goal, false, sizeof(goal));

        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                char c; cin >> c;
                if(c == '.') g[i][j] = 1;
            }
        }
        
        int dir = 0;
        int si = 1;
        int sj = 1;
        
        flag = false;
        dfs(si, sj, dir);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

