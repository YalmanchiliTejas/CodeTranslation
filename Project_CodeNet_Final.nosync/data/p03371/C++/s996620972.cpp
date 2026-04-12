#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1000000001;
    ans = min(ans, a*x+b*y); //全部A B
    ans = min(ans, max(x, y)*c*2);//AB
    if(x>y){
        ans = min(ans, y*2*c+(x-y)*a);
    }
    else{
        ans = min(ans, x*2*c+(y-x)*b);
    }
    cout << ans << endl;
    return 0;
}