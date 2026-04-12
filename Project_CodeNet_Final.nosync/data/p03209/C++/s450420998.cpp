#include <bits/stdc++.h>

#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define ACC(c) (accumulate(ALL(c), 0LL))
#define PRINT(x) cout << (x) << "\n"

using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

inline int in(int& a) {return scanf("%d", &a);}
auto pint_compare = [](pint x, pint y) -> bool{return (x.first < y.first);};
const int MOD = 1000000007;


ll N, X;
ll thick[100];
ll patty[100];

ll dfs(ll i, ll x){
    if(x <= 1) return 0;
    ll ret = 0; x--;
    if(x < thick[i - 1]) return ret + dfs(i - 1, x);
    ret += patty[i - 1]; x -= thick[i - 1];
    if(x <= 0) return ret;
    else if(x == 1) return ret + 1;
    ret++; x--;
    if(x < thick[i - 1]) return ret + dfs(i - 1, x);
    ret += patty[i - 1];
    x -= thick[i - 1];
    return ret;
}

void init(){
    thick[0] = patty[0] = 1;
    REP(i, N){
        thick[i + 1] = 2 * thick[i] + 3;
        patty[i + 1] = 2 * patty[i] + 1;
    }
}

signed main(){
    cin >> N >> X;
    init();
    PRINT(dfs(N, X));
    return 0;
}
