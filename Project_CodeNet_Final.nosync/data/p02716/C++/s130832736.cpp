#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

map<ll, ll> m[200002];
map<ll, bool> used[200002];

vector<long long> A(200002);
long long N;

ll rec(ll n, ll k) {
    if (n <= 0 && k == 0) return 0;
    if ((n + 1) / 2 < k || n <= 0 || k < 0) return -99999999999999999;

    if (used[n][k]) {
        return m[n][k];
    }

    m[n][k] = max(A[N - n] + rec(n - 2, k - 1), rec(n - 1, k));
    used[n][k] = true;
    return m[n][k];
}

int main() {
    scanf("%lld", &N);

    for (int i = 0; i <= N - 1; i++) {
        scanf("%lld", &A[i]);
    }
    // ll res = 0;
    // ll now = 0;
    // if (N % 2 == 0) {
    //     now = 0;
    //     rep(i, N) {
    //         if (i % 2 == 0) now += A[i];
    //     }
    //     res = max(res, now);
    //     now = 0;
    //     rep(i, N) {
    //         if (i % 2 == 1) now += A[i];
    //     }
    //     res = max(res, now);
    //     cout << res << endl;
    // } else {
    //     cout << rec(N, N / 2) << endl;
    // }
    cout << rec(N, N / 2) << endl;
    return 0;
}
