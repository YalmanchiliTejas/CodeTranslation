#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = start; end <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
#define INF32 1'050'000'000
#define INF64 4'000'000'000'000'000'000
using ll = long long;
using namespace std;
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }

ll f(ll N, ll X) {
    if (N==0) return 1;
    ll a = (1LL<<(N+1)) - 3;
    ll p = (1LL<<N) - 1;
    if (X==1) return 0;

    else if (X <= a + 1)
      return f(N-1, X-1);

    else if (X == a + 2)
      return p + 1;

    else if (X <= a * 2 + 4)
      return p + 1 + f(N-1, X-(a+2));

    else return p * 2 + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N; cin >> N;
    ll X; cin >> X;

    cout << f(N, X) << '\n';

    return 0;
}


