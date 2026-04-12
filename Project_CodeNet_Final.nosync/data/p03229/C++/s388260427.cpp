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

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) { cin >> A[i]; }
    sort(A.begin(), A.end(), greater<ll>());
    if(N % 2 == 0) {
        //+2と-2が同じ数
        ll res = 0;
        REP(i, N / 2 - 1) { res += A[i] * 2; }
        res += A[N / 2 - 1];
        res -= A[N / 2];
        for(int i = N / 2 + 1; i < N; i++) {
            res -= A[i] * 2;
        }
        cout << res << endl;
    } else {
        ll res1 = 0;
        for(int i = 0; i < N / 2 - 1; i++) {
            res1 += A[i] * 2;
        }
        res1 += A[N / 2 - 1] + A[N / 2];
        for(int i = N / 2 + 1; i < N; i++) {
            res1 -= A[i] * 2;
        }
        ll res2 = 0;
        for(int i = 0; i < N / 2; i++) {
            res2 += A[i] * 2;
        }
        res2 -= A[N / 2] + A[N / 2 + 1];
        for(int i = N / 2 + 2; i < N; i++) {
            res2 -= A[i] * 2;
        }
        cout << max(res1, res2) << endl;
    }
    return 0;
}