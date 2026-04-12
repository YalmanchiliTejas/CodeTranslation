#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll H,W;
    cin >> H >> W;
    string A[H];
    ll B[H][W];
    rep(i,H){
        rep(j,W) B[i][j] = 0;
    }
    rep(i,H){
        cin >> A[i];
    }
    string out = "Possible";
    ll h = 0;
    ll w = 0;
    while(h<H-1||w<W-1){
        if(h==H-1){
            if(A[H-1][w+1]=='#'){
                B[h][w] = 1;
                w++;
            }
            else{
                out = "Impossible";
                break;
            }
        }else if(w==W-1){
            if(A[h+1][W-1]=='#'){
                B[h][w] = 1;
                h++;
            }
            else{
                out = "Impossible";
                break;
            }
        }else{
            if(A[h][w+1]=='#'&&A[h+1][w]=='.'){
                B[h][w] = 1;
                w++;
            }
            else if (A[h][w+1]=='.'&&A[h+1][w]=='#'){
                B[h][w] = 1;
                h++;
            }
            else{
                out = "Impossible";
                break;
            }
        }
    }
    if(out=="Possible"){
        B[H-1][W-1] = 1;
        rep(i,H){
            rep(j,W){
                if(B[i][j]==0&&A[i][j]=='#'){
                    out = "Impossible";
                    break;
                }
            }
        }
    }
    cout << out << endl;
    return 0;
}
