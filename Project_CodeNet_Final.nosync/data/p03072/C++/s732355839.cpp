#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    ll n;
    cin >> n;

    vector<ll> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    ll mh = h[0];
    ll ans = 1;

    for(int i = 1; i < n; i++){
        if(mh <= h[i]){
            mh = h[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}