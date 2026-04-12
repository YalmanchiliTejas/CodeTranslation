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
    V<ll> a(1, x);//初項から1個目のループ終了までを記憶
    map<ll, int> mp;//mp[i]:初めてiが出たindex
    ll y = x;
    int now = 0; mp[x] = now;
    ll loop_size, loop_start;//loopのサイズと開始のindex
    while (1) {
        now++;//今now項目を見ている
        ll ny = y * y % m;
        if (mp.count(ny)) {//もうnyが出てきてたら
            loop_size = now - mp[ny];
            loop_start = mp[ny];
            break;
        }
        mp[ny] = now;
        a.emplace_back(ny);
        y = ny;
    }
    ll ans = 0;
    
    if (n <= a.size()) {
        rep(i, n) ans += a[i];
        cout << ans << endl;
        return 0;
    }

    rep(i, loop_start) ans += a[i];
    n -= loop_start;
    ll loop_cnt = n / loop_size;
    V<ll> loop(loop_size);
    ll loop_sum = 0;
    for (int i = loop_start; i < a.size(); i++) {
        loop[i - loop_start] = a[i];
        loop_sum += a[i];
    }
    ans += loop_sum * loop_cnt;
    n %= loop_size;
    rep(i, n) ans += loop[i];
    cout << ans << endl;
    return 0;
}