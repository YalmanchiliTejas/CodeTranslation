#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = max(x, y) * c * 2;
    if(x < y){
    	ans = min(ans, x * c * 2 + (y - x) * b);
    }else{
    	ans = min(ans, y * c * 2 + (x - y) * a);
    }
    ans = min(ans, a * x + b * y);
    cout << ans << endl;
    return 0;
}
