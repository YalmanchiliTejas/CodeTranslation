#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void) {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    //ans += (n-k)*(n-k+1)/2;
    //cout << ans << endl;
    if(k==0) ans = n * n;
    else{
        for(ll i = k+1; i <= n; i++){
            ll a = n/i;
            ans += (i-k)*a;
            ll b = n%i;
            if(b>=k) ans += (b-k+1);
            //cout << i << " " << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
