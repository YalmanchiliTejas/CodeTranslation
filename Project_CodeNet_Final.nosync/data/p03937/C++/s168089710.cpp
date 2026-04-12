#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
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

void print(const std::vector<ll> &v) {
    std::for_each(v.begin(), v.end(), [](ll x) { std::cout << x << " "; });
    std::cout << std::endl;
}
// http://drken1215.hatenablog.com/entry/2018/09/09/015414
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    //移動する過程で、駒が常に右または下に動いていた可能性があるか判定してください。
    ll cnt = 0LL;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
            if(A[i][j] == '#') {
                cnt++;
            }
        }
    }
    if(cnt >= H + W) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
    }
    return 0;
}