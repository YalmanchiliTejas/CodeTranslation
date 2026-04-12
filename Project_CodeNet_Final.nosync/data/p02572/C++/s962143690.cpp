#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;

const long long MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }

    ll accum = accumulate(a.begin(), a.end(), 0LL);
    ll ans = 0;
    for(auto x : a){
        accum -= x;
        ll tmp = (accum % MOD) * x;
        ans += tmp;
        ans %= MOD;
    }

    cout << ans << endl;
    return  0;
}