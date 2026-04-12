#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using P = pair<int, int>;

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int NIL = -1;
const ld PI = acosl(-1);

#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(n) n.begin(),n.end()

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vi row, col;
    rep(i, h){
        rep(j, w){
            if(a[i][j] == '#'){
                row.push_back(i);
                break;
            }
        }
    }
    rep(i, w){
        rep(j, h){
            if(a[j][i] == '#'){
                col.push_back(i);
                break;
            }
        }
    }

    for(auto r : row){
        for(auto c : col){
            cout << a[r][c];
        }
        cout << endl;
    }
    return 0;
}