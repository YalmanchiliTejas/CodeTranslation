#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

void solve() {
    int N;
    cin >> N;
    int A[200005];
    rep(i, N) {
        cin >> A[i];
    }
    ll sum = A[N-1];
    ll cur = 0;
    REPR(i, N-2, 0) {
        cur = (cur + sum * A[i]) % MOD;
        sum = (sum + A[i]) % MOD;
    }

    cout << cur;
}

//#define LOCAL 1

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
