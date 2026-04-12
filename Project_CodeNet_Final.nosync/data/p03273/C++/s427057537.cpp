#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <queue>
#include <stack>
#include <string.h>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define repR(i,n) for(int i = n; i >= 0; i--)
#define FOR(i,m,n) for(int i = m; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))


int main(){
    int h,w;
    cin >> h >> w;
    char c[h][w];
    bool y[h], x[w];
    rep(i,h){
        y[i] = false;
        rep(j,w) {
            cin >> c[i][j];
            x[j] = false;
        }
    }
    rep(i,h){
        rep(j,w)if(c[i][j] == '#') y[i] = true;
    }
    rep(j,w){
        rep(i,h)if(c[i][j] == '#') x[j] = true;
    }

    rep(i,h){
        rep(j,w){
            if(y[i] && x[j]) cout << c[i][j];
        }
        if(y[i]) cout << endl;
    }
    return 0;
}