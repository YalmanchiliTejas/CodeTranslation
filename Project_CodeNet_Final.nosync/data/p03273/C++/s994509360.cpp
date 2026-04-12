//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) {
        cin >> a[i];
    }
    queue<int> q;
    set<int> p;
    rep(i, h) {
        bool x = true;
        rep(j, w) {
            if(a[i][j] == '#') x = false;
        }
        if(x) q.push(i);
    }

    rep(i, w) {
        bool x = true;
        rep(j, h) {
            if(a[j][i] == '#') x = false;
        }
        if(x) p.insert(i);
    }

    vs ans;
    rep(i, h) {
        if(!q.empty() and q.front() == i) {
            q.pop();
            continue;
        }
        ans.push_back("");
        rep(j, w) {
            if(p.find(j) == p.end()) {
                *(ans.end()-1) += a[i][j];
            }
        }
    }

    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
}