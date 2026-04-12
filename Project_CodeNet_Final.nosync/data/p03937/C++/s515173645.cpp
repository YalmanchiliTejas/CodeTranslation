#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    int H, W; cin >> H >> W;
    int cnt = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            char c; cin >> c;
            if(c == '#') cnt++;
        }
    }

    if(cnt == H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}