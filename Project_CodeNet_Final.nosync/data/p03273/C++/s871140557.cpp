#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){
    char a[101][101];
    int h, w; cin >> h >> w;

    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }

    vector<bool> row(h, false);
    vector<bool> col(w, false);

    rep(i, h){
        rep(j, w){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    rep(i, h){
        if(row[i]){
            rep(j, w){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
