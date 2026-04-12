#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k == 0){
        cout << n * n << endl;
        return 0;
    }

    for(int b = k + 1; b <= n; b++){
        ll c = n / b;
        ll tmp = c * (b - k);
        tmp += max(ll(0), ll(n % b - max(ll(1), k) + 1));
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}