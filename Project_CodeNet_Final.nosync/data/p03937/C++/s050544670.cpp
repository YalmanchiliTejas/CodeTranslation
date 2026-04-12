#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;

string A[8];

int main(){
    int H;
    int W;

    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> A[i];
    }

    int cur_h = 0;
    int cur_w = 0;
    while(cur_h != H - 1 || cur_w != W - 1){
        A[cur_h][cur_w] = '.';
        if(cur_h + 1 < H && A[cur_h + 1][cur_w] == '#'){
            cur_h ++;
        } else if (cur_w + 1 < W && A[cur_h][cur_w + 1] == '#'){
            cur_w ++;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    
    A[cur_h][cur_w] = '.';
    //cout << cur_h << " " << cur_w << endl;
    //for(int i = 0; i < H; i++){
    //    cout << A[i] << endl;
    //}
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;

    
    return 0;
}
