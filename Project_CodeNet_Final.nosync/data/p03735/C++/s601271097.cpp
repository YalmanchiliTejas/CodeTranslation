#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define repr(i, a, b) for (int i = (int)a; i > (int)b; i--)
#define all(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 1147483600;
const ll infl = 4e18 + 5;
const char ENDL = '\n';
//cout << fixed << setprecision(17) << res << endl;
const ll MOD = 998244353;
typedef pair<int, pll> ppll;
inline bool comp1(ppll a, ppll b) { return a.S.F < b.S.F; }
inline bool comp2(ppll a, ppll b) { return a.S.S < b.S.S; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ppll> ball1(n),ball2(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        if (a>b)
            swap(a, b);
        ball1[i] = ball2[i] = mp(i, mp(a, b));
    }
    sort(all(ball1), comp1);
    sort(all(ball2), comp2);
    ll ans = (ball1[n - 1].S.F - ball1[0].S.F) * (ball2[n - 1].S.S - ball2[0].S.S);
    if (ball1[0].F==ball2[n-1].F){
        cout << ans << ENDL;
        return 0;
    }
    ll kotei = ball2[n - 1].S.S - ball1[0].S.F;
    multiset<ll> have;
    have.insert(ball1[0].S.S);
    repf(i,1,n){
        have.insert(ball1[i].S.F);
    }
    //.fを.sにしていく
    auto itr = have.begin(), ittr = have.end();
    ittr--;
    ans = min(ans, kotei * (*ittr - *itr));
    repf(i,1,n){
        if (ball1[i].F==ball2[n-1].F)
            continue;
        have.erase(have.lower_bound(ball1[i].S.F));
        have.insert(ball1[i].S.S);
        itr = have.begin();
        ittr = have.end();
        ittr--;
        ans = min(ans, kotei * (*ittr - *itr));
    }
    cout << ans << ENDL;
}