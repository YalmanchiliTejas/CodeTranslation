#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

set<char> l = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd',
               'f', 'g', 'z', 'x', 'c', 'v', 'b'};

bool solve() {
    string s;
    cin >> s;
    if(s == "#") {
        return 0;
    }
    int ans = 0;
    int now;
    for(int i = 0; i < s.size(); i++) {
        if(i == 0) {
            now = l.count(s[i]);
        } else {
            int next = l.count(s[i]);
            if(now != next) {
                ans++;
                now = next;
            }
        }
    }
    cout << ans << endl;
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1) {
        if(!solve()) {
            break;
        }
    }
}
