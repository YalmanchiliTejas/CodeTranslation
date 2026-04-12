#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, X, M;
map<ll, ll> mp;
ll acc[100010];

signed main(){
    cin >> N >> X >> M;
    if(N <= M){
        ll ans = X;
        REP(i, N - 1){
            X = X * X % M;
            ans += X;
        }
        PRINT(ans);
        return 0;
    }
    mp[X] = 1; acc[1] = X;
    ll i = 2, j = 0;
    while(i <= N){
        X = X * X % M;
        acc[i] += acc[i - 1] + X;
        if(mp[X] == 0){
            mp[X] = i;
            i++;
        }else{
            j = mp[X];
            break;
        }
    }
    ll k = i - j;
    ll ans = acc[j - 1] + ((N - j + 1) / k) * (acc[i - 1] - acc[j - 1]);
    REP(l, (N - j + 1) % k){
        ans += X;
        X = X * X % M;
    }
    PRINT(ans);
    return 0;
}