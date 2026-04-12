#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    int H,W;
    cin >> H >> W;
    char a[H][W];
    rep(i,H){
        rep(j,W) cin >> a[i][j];
    }
    rep(i,H){
        bool white=true;
        rep(j,W) if(a[i][j] == '#') white=false;
        if(white){
            rep(j,W){
                for(int k=i;k<H-1;k++) a[k][j] = a[k+1][j];
            }
            i--;
            H--;
        }
    }
    rep(j,W){
        bool white=true;
        rep(i,H) if(a[i][j] == '#') white=false;
        if(white){
            rep(i,H){
                for(int k=j;k<W-1;k++) a[i][k] = a[i][k+1];
            }
            j--;
            W--;
        }
    }
    rep(i,H){
        rep(j,W) cout << a[i][j];
        cout << endl;
    }
}