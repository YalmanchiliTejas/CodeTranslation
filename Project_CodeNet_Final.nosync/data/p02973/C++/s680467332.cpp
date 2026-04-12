#include "bits/stdc++.h"
// Custom Header {{{
#define ALL(x) x.begin(), x.end()
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

#ifdef YDK
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    i64 a[100010];

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    multiset<i64> pend;
    pend.insert(a[0]);

    for (int i = 1;i < N; ++i) {
        auto it = pend.lower_bound(a[i]);
        if (it == pend.begin()) {
            pend.insert(a[i]);
            eprintf("%lld just insert\n", a[i]);
        } else {
            --it;
            const auto tmp = *it;
            pend.erase(it);
            pend.insert(a[i]);
            eprintf("%lld %lld update insert\n", a[i], tmp);
        }
    }

    cout << pend.size() << endl;

    return 0;
}

// vim: set foldmethod=marker :
