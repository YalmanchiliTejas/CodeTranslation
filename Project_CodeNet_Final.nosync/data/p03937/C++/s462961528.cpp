#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int H,W;cin >> H >> W;
    vector<vector<bool>> on(H+1,vector<bool>(W+1,false));
    rep(i,H)rep(j,W){
        char t;cin >> t;
        if(t == '.')on[i][j] = false;
        else on[i][j] = true;
    }


    int lim = H+W-2;
    on[0][0] = false;
    on[H-1][W-1] = false;
    int x = 0;
    int y = 0;
    rep(i,lim-1){
        if(x != H-1){
            if(on[x+1][y]){
                on[x+1][y] = false;
                x += 1;
//                cout << "(" << x << "," << y << ")";
                continue;
            }
        }
        if(y != W-1){
            if(on[x][y+1]){
                on[x][y+1] = false;
                y += 1;
//                cout << "(" << x << "," << y << ")";
                continue;
            }
        }
    }


    bool pos = true;
    rep(i,H)rep(j,W){
        if(on[i][j]) pos = false;
    }

    if(pos)cout << "Possible" << endl;
    else cout << "Impossible" << endl;

/*    rep(i,H){
        rep(j,W){
            if(on[i][j])cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
*/
}
