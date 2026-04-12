#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
const int INF = 1e9;

int a,b,c,x,y;

int main(){
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int m = min(x,y);
    if(a+b > c*2){
        ans += m * c * 2;

        if(x > y){
            if(a > c * 2) ans += c * 2 * (x-y);
            else ans += a * (x-y);
        } else if(x < y) {
            if(b > c * 2) ans += c * 2 * (y-x);
            else ans += b * (y-x);
        }
    } else {
        ans = a * x + b * y;
    }
    cout << ans << endl;
}