#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <numeric>
#include <climits>
#include <math.h>
#include <memory.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for(int i = (k); i < (int)(n); i++)
using namespace std;
using ll = long long;
int N, M;
int cnt = 0;
int ans = 0;
int i_index;
int tmp;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};
string board[64];
string a[64];
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    N = min(C * 2, A + B);//A, Bそれぞれ1枚買う際に安い方
    
    int z = min(X, Y);//X, Y少ない方
    ans = z * N;
    int dx = X - z;
    int dy = Y - z;
    int xx = min(dx * A, dx * N);
    int yy = min(dy * B, dy * N);
    ans += xx + yy;
    /*if(N == C * 2 && X < Y){
        ans += N * (Y - X);
    }
    else if(N == C * 2 && X >= Y){
        ans += N * (X - Y);
    }
    else
        ans += (X - z) * A + (Y - z) * B;*/
    //if(Y > X)
    //    ans -= (Y - X);
    cout << ans << endl;
    return 0;
}