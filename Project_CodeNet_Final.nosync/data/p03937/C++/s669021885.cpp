#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repp(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
using namespace std;
typedef pair<int, int> P;
char c[10][10];

signed main(){
	int h, w;
    cin >> h >> w;
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> c[i][j];
        }
        c[i][w] = '.';
    }
    bool f = true;
    int x = 0;
    rep(i, 0, h){
        rep(j, x, w + 1){
            if(c[i][j] == '#'){
                c[i][j] = '.';
            }else{
                x = j - 1;
                break;
            }
        }
    }
    rep(i, 0, h) rep(j, 0, w) if(c[i][j] == '#') f = false;
    if(f) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}