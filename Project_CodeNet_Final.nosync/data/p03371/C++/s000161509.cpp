#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1e18;
    rep(i,max(x,y)+1){
        ll tmp = c*i*2;
        tmp += max(0,x-i)*a;
        tmp += max(0, y - i) * b;
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}