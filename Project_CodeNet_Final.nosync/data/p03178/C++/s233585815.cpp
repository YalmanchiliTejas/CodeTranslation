#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    string K;
    int D;
    cin >> K >> D;

    const ll MOD = 1e9+7;
    Vvec<ll> dp(D, vector<ll>(2));
    Vvec<ll> next(D, vector<ll>(2));
    dp[0][1] = 1;

    for(int i=0; i<K.size(); i++){
        int n = K[i] - '0';
        for(int j=0; j<D; j++){
            for(int k=0; k<10; k++){
                int r = (j+k) % D;
                next[r][0] += dp[j][0];
                next[r][0] %= MOD;
            }
            for(int k=0; k<n; k++){
                int r = (j+k) % D;
                next[r][0] += dp[j][1];
                next[r][0] %= MOD;
            }
            int r = (j+n) % D;
            next[r][1] += dp[j][1];
            next[r][1] %= MOD;
        }

        for(int j=0; j<D; j++){
            dp[j][0] = next[j][0];
            dp[j][1] = next[j][1];
            next[j][0] = 0;
            next[j][1] = 0;
        }
    }

    ll ans = dp[0][0] + dp[0][1] - 1;
    if(ans < 0) ans += MOD;
    cout << ans % MOD << endl;
}