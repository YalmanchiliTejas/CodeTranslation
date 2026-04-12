#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

ll INF = 1 << 60;

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
    return 0;
}