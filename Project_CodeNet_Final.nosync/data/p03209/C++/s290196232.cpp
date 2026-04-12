#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)

#define D1(a) cout<<#a<<":"<<a<<"\n"
#define D2(a,b) cout<<#a<<":"<<a<<","<<#b<<":"<<b<<endl 
#define D3(a,b,c) cout<<#a<<":"<<a<<","<<#b<<":"<<b<<","<<#c<<":"<<c <<endl
#define D4(a,b,c,d) cout<<#a<<":"<<a<<","<<#b<<":"<<b<<","<<#c<<":"<<c<<","<<#d<<":"<<d<<endl 

template <class INT_T> INT_T powi(INT_T x, INT_T y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y & 1) return powi(x*x, y/2) * x;
    return powi(x*x, y/2);
}

ll solve(map<pll, ll>& memo, ll lv, ll eat)
{
    ll len = 4 * powi((ll)2, lv) - 3;

    auto p = make_pair(lv, eat);
    if (memo.find(p) != memo.end()) {
        return memo[p];
    }
    
    ll c = (len + 1) / 2;
    ll res = eat >= c ? 1 : 0;

    if (lv > 0) {
        ll eat_max = (len - 3) / 2;
        res += solve(memo, lv-1, min(eat-1, eat_max));
        if (eat > c) {
            res += solve(memo, lv-1, min(eat-c, eat_max));
        }
    }
    
    return memo[p] = res;
}


int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    map<pll, ll> memo;

    cout << solve(memo, n, x) << endl;
}
