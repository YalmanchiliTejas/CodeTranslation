#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll ans = 1002003004;

    ans = min(ans, a*x+b*y);
    ans = min(ans, max(x,y)*2 * c);
    if(x >= y) ans = min(ans, y*2 * c + (x-y) * a);
    if(x < y)  ans = min(ans, x*2 * c + (y-x) * b);

    cout << ans << endl;
}