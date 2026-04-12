#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if ( k == 0 ) {
        cout << n * n << endl;
        return 0;
    }
    for ( ll i = k + 1; i <= n; ++i ) {
        ll mod_group_num = ( n + 1 ) / i;
        ans += mod_group_num * ( i - k );
        ll num = ( n + 1 ) % i;
        ans += max(0LL, num - k);
    }
    cout << ans << endl;
    return 0;
}
