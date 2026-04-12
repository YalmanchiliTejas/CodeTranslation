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
const ll mod = 1000000007;
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}
ll N;
vector<ll> h;
ll ans = 1;

void print(l_l tmp) {
    cerr << "{" << tmp.first << ", " << tmp.second << "}" << endl;
}

l_l f(ll l, ll r, ll d) {
    l_l ret;
    /*
    if(r == l + 1) {
        ret.second = beki(2, h[l] - d);
        cerr << "f: " << l << " " << r << " " << d << endl;
        print(ret);
        return ret;
    }
    */
    ll mini = 1e10;
    ll maxi = 0;
    for(int i = l; i < r; i++) {
        chmin(mini, h[i]);
        chmax(maxi, h[i]);
    }
    if(mini == maxi) {
        ret.first = beki(2, r - l) - 2 + mod;
        ret.first %= mod;
        ret.second = 2 * beki(2, maxi - d - 1);
        ret.second %= mod;
        //cerr << "f: " << l << " " << r << " " << d << endl;
        //print(ret);
        return ret;
    }
    ll Left = l;
    ll mininum = 0;
    vector<l_l> v;
    for(int i = l; i < r; i++) {
        if(h[i] == mini) {
            mininum++;
            if(Left != i) {
                v.push_back(f(Left, i, mini));
            }
            Left = i + 1;
        }
    }
    if(Left != r) {
        v.push_back(f(Left, r, mini));
    }
    ll total = beki(2, mininum);
    ll Second = 2;
    for(auto tmp : v) {
        total *= tmp.first + tmp.second * 2;
        total %= mod;
        Second *= tmp.second;
        Second %= mod;
    }
    ret.second = Second;
    ret.first = total - Second + mod;
    ret.first %= mod;
    ret.second *= beki(2, mini - d - 1);
    ret.second %= mod;
    //cerr << "f: " << l << " " << r << " " << d << endl;
    //print(ret);
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    h.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }
    ll l = 0;
    for(int r = 0; r < N; r++) {
        if(h[r] == 1) {
            ans *= 2;
            if(l != r) {
                auto tmp = f(l, r, 0);
                ans *= tmp.first + tmp.second;
                ans %= mod;
            }
            l = r + 1;
        }
    }
    if(l != N) {
        auto tmp = f(l, N, 0);
        ans *= tmp.first + tmp.second;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}