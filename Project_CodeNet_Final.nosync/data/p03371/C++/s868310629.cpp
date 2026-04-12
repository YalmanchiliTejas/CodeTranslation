#include <string>
#include <iostream>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    ll ans = LLONG_MAX;
    FOR(i, 0, 100001) {
        ans = min(ans, 2 * C * i + max(X - i, 0LL) * A + max(Y - i, 0LL) * B);
    }
    cout << ans << endl;

    return 0;
}