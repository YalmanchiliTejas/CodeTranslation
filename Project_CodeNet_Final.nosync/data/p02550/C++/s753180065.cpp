//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define V vector
template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}
V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    ll n, x, m; cin >> n >> x >> m;
    V<ll> a(1, x);
    map<ll, int> mp;
    ll y = x;
    mp[x] = 0;
    int cnt = 0;
    int loop_s, loop;
    while (true) {
        cnt++;
        ll ny = (y * y) % m;
        if (mp.count(ny)) {
            loop_s = ny;
            loop = cnt - mp[ny];
            break;
        }
        a.emplace_back(ny);
        mp[ny] = cnt;
        y = ny;
    }
    int s = mp[loop_s];
    ll ans = 0;
    rep(i, s) ans += a[i];
    ll loop_sum = 0;
    V<ll> loopp(loop);
    for (int i = s; i < a.size(); i++) {
        loopp[i-s] = a[i];
        loop_sum += a[i];
    }
    n -= s;
    ll loop_num = n / loop;
    ans += loop_sum * loop_num;
    n -= loop * loop_num;
    rep(i, n) ans += loopp[i];
    cout << ans << endl;

    return 0;
}