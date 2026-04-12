#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

ll solve(ll l, ll x){
    ll ans;
    if(x == 0){
        return 0;
    }
    if(l == 0){
        return 1;
    }
    ll mid = (pow(2, l + 2) - 3) / 2;
    if(mid >= x){
        ans = solve(l - 1, x - 1);
        // バンズ引く
    }else if(mid + 1 == x){
        ans = solve(l - 1, x - 1) + 1;
    }else{
        ll tmp = pow(2, (l + 1) - 1) - 1;
        ll tmp2 = solve(l - 1, x - mid - 1);
        ans = tmp + tmp2 + 1;
    }
    return ans;
}


int main(){
    ll N, X;
    cin >> N >> X;
    ll ans = solve(N, X);
    cout << ans << endl;
}
