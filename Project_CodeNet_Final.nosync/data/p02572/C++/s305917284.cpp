#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void) {
    int n;
    cin >> n;

    vector<llint> a(n);
    vector<llint> s(n+1, 0);
    for(int in=0;in<n;++in) {
        cin >> a[in];
        s[in+1] = s[in] + a[in];
    }

    llint ans = 0, tmp1;
    for(int in=0;in<n-1;++in) {
        tmp1 = s[n] - s[in+1];
        tmp1 %= MOD;
        if(tmp1<0) tmp1 += MOD;
        ans += a[in]*tmp1;
        ans %= MOD;
        if(ans<0) ans += MOD;
    }

    cout << ans << endl;
    return 0;
}
