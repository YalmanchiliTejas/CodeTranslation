#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>

using namespace std;

#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)

using ll = long long;
#define int ll
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n+2, 0);
    rep(i, n) {
        cin >> a[i];
    }
    vector<int> cumsum(n+2, 0);

    REP(i, 0, n) {
        cumsum[i+1] = (cumsum[i] + a[i])%mod;
    }
    int res =0;
    rep(i, n-1) {
        res += ((cumsum[n] - cumsum[i+1]+mod) % mod)*a[i]%mod;
        res = res % mod;
    }

    cout << res << "\n";
}