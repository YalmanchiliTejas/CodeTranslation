#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;

vector<pair<int, int> > vx;
vector<pair<int, int> > vy;

vector<tuple<ll, int, int> > ed;
int p[120000];

int get(int a) {
    if (p[a] == a)
        return a;
    return p[a] = get(p[a]);
}

int un(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return 0;
    p[a] = b;
    return 1;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vx.push_back(make_pair(x, i));
        vy.push_back(make_pair(y, i));
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    for (int i = 0; i < n; ++i)
        p[i] = i;
    for (int i = 0; i < vx.size() - 1; ++i) {
        ll d = abs(vx[i].first - vx[i + 1].first);
        ed.push_back(make_tuple(d, vx[i].second, vx[i + 1].second));
    }
    for (int i = 0; i < vy.size() - 1; ++i) {
        ll d = abs(vy[i].first - vy[i + 1].first);
        ed.push_back(make_tuple(d, vy[i].second, vy[i + 1].second));
    }
    sort(ed.begin(), ed.end());
    ll ans = 0;
    for (int i = 0; i < ed.size(); ++i) {
        ll d;
        int a, b;
        tie(d, a, b) = ed[i];
        if (un(a, b))
            ans += d;
    }
    cout << ans << "\n";
    return 0;
}


