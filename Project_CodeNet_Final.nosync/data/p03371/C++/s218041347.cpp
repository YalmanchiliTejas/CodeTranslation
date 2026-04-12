#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ll_min(ll a, ll b){
    if (a < b) return b;
    else return b;
}

ll ll_max(ll a, ll b){
    if (a > b) return a;
    else return b;
}

int main(void){
    ll A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    ll C_ = C * 2;
    
    ll ans = 999999999999;
    for (int i = 0; i <= max(X,Y); i++){
        ll tmp_cost = 0;
        tmp_cost += C_ * i;
        tmp_cost += ll_max(0, (X-i) * A);
        tmp_cost += ll_max(0, (Y-i) * B);
        ans = min(ans, tmp_cost);
    }
    cout << ans << endl;
}
