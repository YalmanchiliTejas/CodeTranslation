#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
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

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(26, 1e5);
    while(n--) {
        string s;
        cin >> s;
        vector<int> b(26, 0);
        for(char c : s) {
            b[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            a[i] = min(a[i], b[i]);
        }
    }
    string ans = "";
    for(int i = 0; i < 26; i++) {
        // cout << a[i] << endl;
        ans += string(a[i], 'a' + i);
    }
    cout << ans << endl;
    return 0;
}