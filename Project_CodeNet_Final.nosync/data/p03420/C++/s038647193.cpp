#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define iter(v, i) for (__typeof__((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fast_io_without_cstdio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(v) (v).begin(), (v).end()
#define rep(i, s, e) for (int i = s; i < e; i++)

// START for segment tree
#define params int p, int L, int R
#define housekeep int mid = (L + R) >> 1, left = p << 1, right = left | 1
// END

#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif

#if __cplusplus <= 199711L
template<class BidirIt>
BidirIt prev(BidirIt it, typename iterator_traits<BidirIt>::difference_type n = 1) {
    advance(it, -n);
    return it;
}

template<class ForwardIt>
ForwardIt next(ForwardIt it, typename iterator_traits<ForwardIt>::difference_type n = 1) {
    advance(it, n);
    return it;
}
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ldouble;

const double EPS = 1e-9;
const double PI = 3.141592653589793238462;

template<typename T>
inline T sq(T a) { return a * a; }

//#ifdef LOCAL_MACHINE
//#endif

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 0) {
        printf("%lld\n", n * 1LL * n);
        return 0;
    }
    ll ans = 0;
    for (int b = k + 1; b <= n; b++) {
        int last = b;
        for (int j = b; j <= n; j += b) {
            ans += b - k;
            last = j;
        }
        if (last + k <= n)
            ans += max(0, n - (last + k) + 1);
    }
    printf("%lld\n", ans);
    return 0;
}

