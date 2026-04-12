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
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;


    if(a+b <= 2*c){
        cout << a*x + b*y << endl;
    }
    else{
        if(x <= y){
            int ans = 0;
            ans += 2*c*x;
            ans += min((y-x)*b, 2*c*(y-x));
            cout << ans << endl;
        }
        else{
            int ans = 0;
            ans += 2*c*y;
            ans += min((x-y)*a, (x-y)*2*c);
            cout << ans << endl;
        }
    }
}