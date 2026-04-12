#include <bits/stdc++.h>
using namespace std;

int64_t N,X;
vector<int64_t> W; // レベルxのときの層の数
vector<int64_t> P; // レベルxのときのパティの数

// レベルxバーガーのy層目まで食べる
int64_t dfs(int64_t x, int64_t y) {
    if ( x == 1 ){
        if ( y <= 1 ) return 0;
        else if ( y == 2 ) return 1;
        else if ( y == 3 ) return 2;
        else if ( y >= 4 ) return 3;
    }
    int64_t w = W[x-1];
    w = w/2;
    int64_t ans;
    if ( y <= w ) {
        ans = dfs(x-1,y-1);
    } else if ( y == w+1 ) {
        //ans = dfs(x-1,w) + 1;
        ans = P[x-2] + 1;
    } else {
        //ans = dfs(x-1,y-w-1) + dfs(x-1,w) + 1;
        ans = dfs(x-1,y-w-1) + P[x-2] + 1;
    }
    return ans;
}

int main() {
    cin >> N >> X;
    W.resize(N);
    P.resize(N);
    W[0] = 5;
    P[0] = 3;
    for ( int64_t i = 1; i < N; ++i){
        W[i] = W[i-1] * 2 + 3;
        P[i] = P[i-1] * 2 + 1;
    }
    
    cout << dfs(N,X) << endl;
    
    return 0;
}
