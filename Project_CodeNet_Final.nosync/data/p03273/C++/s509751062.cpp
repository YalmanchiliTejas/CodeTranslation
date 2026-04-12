#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define rn return
typedef std::pair<int,int> P;
using namespace std;
using ll = long long;


int main(){
    int N,W; cin >> N  >> W;
    vector<vector<char>> C(N,vector<char>(W));
    rep(i,N){rep(j,W) cin >> C[i][j];};
    vector<int> goodi(N);
    vector<int> goodj(W);
    rep(i,N){
        rep(j,W){
            if (C[i][j] == '#') {goodi[i] = 1; goodj[j] = 1;};
        }
    }
    
    rep(i,N){
        rep(j,W){
            if (goodi[i] == 1 & goodj[j] == 1) cout << C[i][j];
        }
        if (goodi[i]) cout << endl;
    }
    
    rn 0;
}