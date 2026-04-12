#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define UI unsigned int
#define mem(i, j) memset(i, j, sizeof(i))
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define dep(i, j, k) for(int i = k; i >= j; i--)
#define pb push_back
#define make make_pair
#define INF 0x3f3f3f3f
#define inf LLONG_MAX
#define PI acos(-1)
#define fir first
#define sec second
#define lb(x) ((x) & (-(x)))
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

const int N = 1e6 + 5;

const LL mod = 1e9 + 7;

int n;

LL a[N];

void solve() {

    scanf("%d", &n);

    rep(i, 1, n) scanf("%lld", &a[i]);

    LL s = a[1];

    LL ans = 0;

    rep(i, 2, n) {

        ans = (ans + a[i] * s % mod) % mod;

        s = (s + a[i]) % mod;

    }

    printf("%lld\n", ans);

}


int main() {

//    int _; scanf("%d", &_);
//    while(_--) solve();

    solve();

    return 0;
}
