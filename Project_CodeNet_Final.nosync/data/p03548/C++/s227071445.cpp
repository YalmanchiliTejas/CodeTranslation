#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

//INT_MAX	2,147,483,647 = 2*1.0e9

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int X,Y,Z; cin >> X >> Y >> Z;
    int ans = 0;

    X -= 2 * Z;
    if(X>=Y){
        ans++;
        X-=Y;
    }

    if(X> 0) ans += X/(Y+Z);

    cout << ans << endl;

    return 0;
}
