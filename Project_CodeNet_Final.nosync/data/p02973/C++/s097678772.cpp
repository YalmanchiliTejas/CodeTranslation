#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<long long> &v) {
    std::for_each(v.begin(), v.end(),
                  [](long long x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    REP(i, N) { cin >> a[i]; }
    deque<long long> d;
    REP(i, N) {
        int p = lower_bound(d.begin(), d.end(), a[i]) -
                d.begin(); //以上の最初の場所
        if(p == 0) {
            d.push_front(a[i]);
        } else
            d[p - 1] = a[i];
    }
    int ans = d.size();
    cout << ans << endl;
    return 0;
}