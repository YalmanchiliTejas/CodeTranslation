#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a*x + b*y;
    if(x < y){
    	chmin(ans, c*2*x + b*(y-x));
    	chmin(ans, c*2*y);
    }
    else{
    	chmin(ans, a*(x-y) + c*2*y);
    	chmin(ans, c*2*x);
    }
    cout << ans << endl;
    return 0;
}