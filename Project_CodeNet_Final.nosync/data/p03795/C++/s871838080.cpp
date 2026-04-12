#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<ll, ll> P;

// 移動を簡単に表現するための配列
int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};

int main() {
    int n; cin >> n;
    int ans = 800 * n;
    ans -= (n/15)*200;
    cout << ans << endl;
    return 0;
}
