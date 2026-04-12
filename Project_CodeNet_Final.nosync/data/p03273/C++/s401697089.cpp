#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define rep(i, n) for(int i=0; i<n; ++i)
#define REP(i, n) for(int i=1; i<=n; ++i)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 100100100;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    int h, w; cin >> h >> w;
    vector<str> grid;
    rep(i, h){
        str s; cin >> s;
        rep(i, w){
            if(s[i] == '#'){
                grid.push_back(s);
                break;
            }
        }
    }
    vector<int> okay;
    rep(i, w){
        rep(j, grid.size()){
            if(grid[j][i] == '#'){
                okay.push_back(i);
                break;
            }
        }
    }
    rep(i, grid.size()){
        rep(j, okay.size()){
            cout << grid[i][okay[j]];
        }
        cout << endl;
    }
    return 0;
}