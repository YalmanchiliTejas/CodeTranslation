#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < N; X++)
#define PI (acos(-1.0))

using namespace std;

int main(){

    int a,b,c,x,y;

    cin >> a >> b >> c >> x >> y;

    x = x * 2;
    y = y * 2;

    ll ans = LLONG_MAX;

    rep(i,max(x,y) + 1){

        ll needx = max((ll)0,(x - i + 1) / 2);
        ll needy = max((ll)0,(y - i + 1) / 2);

        ans = min(ans, needx * a + needy * b + i * c);
    }

    cout << ans << endl;
 
    return 0;
}