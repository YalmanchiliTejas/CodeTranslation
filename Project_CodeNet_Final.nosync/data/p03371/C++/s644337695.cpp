#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXZ = 1e5;
const ll INF = ll(1e18)+5;

//https://atcoder.jp/contests/abc095/tasks/arc096_a
int main() {
    ll A,B,C,X,Y;
    cin >> A >> B >>C>>X >>Y;
    ll ans = INF;
    for(int z=0;z <=MAXZ;z++){
        ll x = max(0ll,X-z);
        ll y = max(0ll,Y-z);
        ans = min(ans,x*A+ y*B+z*C*2);
    }
    cout << ans << endl;

    return 0;
}