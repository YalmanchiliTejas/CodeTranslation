#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pow(x) x*x
#define ll long long
static const int MAX = 10000;
static const ll INFTY = 1e12;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
// 入力
int H, W, N;
int sx, sy, gx, gy; 
vector<vector<char>> field;
vector<vector<int>> dist;
queue<pair<int, int>> que;

int main() {

    int N, M;
    int s[10][10] = {0};
    bool flag = true;
    int count = 0;

    cin >> N >> M;

    REP(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        s[a][b] = s[b][a] = 1;
    }

    int n;
    vector<int> one_case;
    vector<int> one_case_cpy;
    for (int i = 1; i < N; i++) { // one_case = {1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }
    do {
        one_case_cpy = one_case;
        one_case_cpy.insert(one_case_cpy.begin(), 0);
        flag = true;
        REP(i, N-1){
            if( s[one_case[i]][one_case[i+1]] != 1 ) {
                flag = false;
                break;
            }
        }
        if(flag == true){
            count++;
        }
        
    } while (next_permutation(one_case.begin(), one_case.end()));
    // 順列の最後になるまで one_case を並び替えながらループ

    cout << count << endl;

    return 0;

}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/