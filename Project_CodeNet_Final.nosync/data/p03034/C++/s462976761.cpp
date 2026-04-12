#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll s[100050];
ll ans = 0;
ll used[100050];
void f(ll delta) {
    ll score = 0;
    for(ll i = 1; ; i++) {
        ll now = N - 1 - i * delta;
        if(now < delta) break;
        if(used[now] == delta) break;
        score += s[now];
        used[now] = delta;
        now = i * delta;
        if(used[now] == delta) break;
        score += s[now];
        used[now] = delta;
        chmax(ans, score);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> s[i];
    for(ll delta = 1; delta <= N - 1; delta++) {
        f(delta);
    }
    cout << ans << endl;
    return 0;
}
