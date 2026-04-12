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

inline int std_in(int& a) {return scanf("%d", &a);}
auto pint_compare = [](pint x, pint y) -> bool{return (x.first < y.first);};
const int MOD = 1000000007;

signed main(){
    string S;
    cin >> S;
    if(S[0] == S[1] && S[1] == S[2]) PRINT("No");
    else PRINT("Yes");
    return 0;
}