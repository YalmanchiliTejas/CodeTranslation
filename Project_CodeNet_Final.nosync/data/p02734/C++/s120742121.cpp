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
    const ll MOD = 998244353;
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for(auto& x: A) cin >> x;

    vector<ll> dp(S+1);
    ll ans = 0;
    for(int i=0; i<N; i++){
        ll p = dp[S];
        for(int j=S; j>=0; j--){
            if(j-A[i]>0) dp[j] += dp[j-A[i]];
            if(j-A[i]==0) dp[j] += i+1;
            dp[j] %= MOD;
        }
        ll n = dp[S] - p;
        if(n<0) n += MOD;
        ans += n * (N-i);
        ans %= MOD;
        // debug(dp);
    }

    cout << ans << endl;
}