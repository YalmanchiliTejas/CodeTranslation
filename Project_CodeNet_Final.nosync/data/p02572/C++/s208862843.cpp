#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <list>
#include <set>
#include <random>
#include <deque>
#include <unordered_set>

using namespace std;
using ll = long long;
const int BIG = 1000000007;


int main() {
    ll n;
    cin >> n;
    ll a = 0;
    ll b = 0;
    for(ll i = 0;i < n;++i){
        ll l;
        cin >> l;
        a += l;
        b += l * l;
        a %= BIG;
        b %= BIG;
    }
    ll ans = a * a - b;
    ans = (ans < 0) ? (BIG + ans) : ans;
    ans %= BIG;

    if(ans % 2 == 1){
        ans += BIG;
    }
    ans /= 2;
    cout << ans << endl;
}


