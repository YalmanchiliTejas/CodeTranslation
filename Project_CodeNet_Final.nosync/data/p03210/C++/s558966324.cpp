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

signed main(){
    int X;
    cin >> X;
    if(X == 7 || X == 5 || X == 3) PRINT("YES");
    else PRINT("NO");
    return 0;
}