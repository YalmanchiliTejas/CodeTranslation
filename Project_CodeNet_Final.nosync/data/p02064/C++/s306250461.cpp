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
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

using P = pair<int, int>;

void ask(int u, int v) { cout << "? " << u << " " << v << endl; }

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> ds(n + 1), dt(n + 1);
    for(int i = 1; i <= n; i++) {
        if(s == i) {
            continue;
        }
        ask(s, i);
        cin >> ds[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == t) {
            continue;
        }
        ask(i, t);
        cin >> dt[i];
    }
    vector<P> kouho;
    for(int i = 1; i <= n; i++) {
        if(i == s || i == t) {
            continue;
        }
        if(ds[i] + dt[i] == ds[t]) {
            kouho.emplace_back(P(ds[i], i));
        }
    }
    sort(ALL(kouho));
    vector<int> ans;
    if(kouho.size()) {
        ans.emplace_back(kouho[0].second);
    }
    for(int i = 1; i < kouho.size(); i++) {
        ask(ans.back(), kouho[i].second);
        int tmp;
        cin >> tmp;
        if(ds[ans.back()] + tmp == ds[kouho[i].second]) {
            ans.emplace_back(kouho[i].second);
        }
    }
    cout << "! " << s << " ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << t << endl;
}
