// a code about cooties
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(int)(a);i--)
template<typename T> ostream& operator<<(ostream& s, vector<T> t) {rep(i, 0, t.size()) s << (i ? " " : "") << t[i]; return s;}
template<typename T> istream& operator>>(istream& s, vector<T> &t) {rep(i, 0, t.size()) s >> t[i]; return s;}
template<typename T, typename U> ostream& operator<<(ostream& s, pair<T, U> t) {s << "(" << t.first << "," << t.second << ")"; return s;}
template<typename T, typename U> istream& operator>>(istream& s, pair<T, U> &t) {s >> t.first >> t.second; return s;}
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pt> a(n);
    cin >> a;
    rep(i, 0, n) if (a[i].y > a[i].x) swap(a[i].x, a[i].y);
    ll mxx = 0, mxy = 0, mnx = INF, mny = INF;
    rep(i, 0, n) {
        mnx = min(mnx, a[i].x);
        mny = min(mny, a[i].y);
        mxx = max(mxx, a[i].x);
        mxy = max(mxy, a[i].y);
    }
    ll res = (mxx - mnx) * (mxy - mny);
    mnx = mny;
    sort(a.begin(), a.end(), [](const pt & pa, const pt & pb) {
        return pa.y < pb.y;
    });
    set<pt> s;
    rep(i, 0, n) s.insert({a[i].y, a[i].x});
    while (true) {
        pt cur = *s.begin();
        if (cur.second <= cur.first) break;
        s.erase(s.begin());
        s.insert({cur.second, cur.first});
        mny = s.begin()->first;
        mxy = (--s.end())->first;
        
        //cout << mny << " " << mxy << endl;
        res = min(res, (mxx - mnx) * (mxy - mny));
        
    }
    
    cout << res << endl;
}
