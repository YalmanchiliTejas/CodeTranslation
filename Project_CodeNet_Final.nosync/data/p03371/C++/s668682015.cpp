#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    if(x<y){swap(x, y); swap(a,b);}
    if(x==y && a > b){swap(a,b);}
    ll ans = INF64;
    ans = min(ans, x*a+y*b);
    ans = min(ans, y*2*c+(x-y)*a);
    ans = min(ans, x*2*c);
    cout << ans << endl;
    return 0;
}