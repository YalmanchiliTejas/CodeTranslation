#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

int main(void){
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    int ans = 0;
    if(a+b >= 2*c){
        ans += min(x, y)*2*c;
        int minv = min(x, y);
        x -= minv;
        y -= minv;

        if(x == y) cout << ans << endl;
        else if(x > 0) cout << ans + x*min(2*c, a) << endl;
        else cout << ans + y*min(2*c, b) << endl;
    }
    else{
        cout << a*x + b*y << endl;
    }
}