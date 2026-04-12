#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    multiset<ll> s;

    for (ll i = 0; i < n; ++i) {
        ll now = a[i];
        auto itr = s.lower_bound(now);
        if (itr != s.begin()) s.erase(--itr);
        s.insert(now);
    }

    cout << s.size() << endl;

}
