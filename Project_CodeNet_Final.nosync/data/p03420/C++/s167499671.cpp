#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
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
        int mod_group_num = n / i;
        int cntup_num = i - k;
        int rest_num = n - mod_group_num * i;
        int add_cntup_num = max(0LL, rest_num - k + 1);
        ans += cntup_num * mod_group_num + add_cntup_num;
    }
    cout << ans << endl;
    return 0;
}
