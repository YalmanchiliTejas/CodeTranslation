#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
typedef pair<pl, int> pli;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

bool dead[300];
int n, s, t;
pli dist[300];
ll all;

ll ask (int a, int b) {
    a++; b++;
    if (a == b) return 0;
    cout << "? " << a << " " << b << endl;
    cout.flush();
    ll d; cin >> d;
    return d;
}

int main() {
    cin >> n >> s >> t;
    s--; t--;
    all = ask(s, t);
    dist[s] = pli(pl(0, all), s);
    dist[t] = pli(pl(all, 0), t);
    rep(i,n) {
        if (i == s || i == t) continue;
        dist[i] = pli(pl(ask(s,i), ask(i,t)), i);
    }
    sort(dist, dist+n);
    vector<int> ans;
    int pos = 0;
    rep(i,n) {
        if (dist[i].first.first + dist[i].first.second != all) continue;
        ll mid = ask(dist[pos].second, dist[i].second);
        if (dist[pos].first.first + mid + dist[i].first.second == all) {
            pos = i;
            ans.push_back(dist[i].second);
        }
    }
    cout << "!";
    rep(i,ans.size()) cout << " " << ans[i]+1;
    cout << endl;
}

