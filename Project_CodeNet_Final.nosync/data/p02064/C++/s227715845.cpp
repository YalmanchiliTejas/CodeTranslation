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
ll total;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, t, s;
    cin >> N >> s >> t;
    cout << "? " << t << " " << s << endl;
    cin >> total;
    vector<l_l> v;
    v.push_back({total, t});
    v.push_back({0, s});
    for(int i = 1; i <= N; i++) {
        if(i == t || i == s) continue;
        cout << "? " << t << " " << i << endl;
        ll tdist, sdist;
        cin >> tdist;
        cout << "? " << s << " " << i << endl;
        cin >> sdist;
        if(sdist + tdist != total) continue;
        v.emplace_back(sdist, i);
    }
    sort(v.begin(), v.end());
    ll now = s;
    ll nowdist = 0;
    vector<int> ans;
    ans.push_back(s);
    for(int i = 1; i < v.size(); i++) {
        cout << "? " << now << " " << v[i].second << endl;
        ll sub;
        cin >> sub;
        if(sub + nowdist == v[i].first) {
            ans.push_back(v[i].second);
            now = v[i].second;
            nowdist = v[i].first;
        }
    }
    cout << "!";
    for(int i = 0; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
    return 0;
}

