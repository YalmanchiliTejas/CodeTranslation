#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    int n;
    cin >> n;
    vector<ll> vs(n);
    rep(i, n) {
        cin >> vs[i];
    }
    multiset<int> colors;
    colors.insert(vs[0]);
    for (int i = 1; i < n; i++) {
        auto item = vs[i];
        auto it = colors.lower_bound(item);
        if (it == colors.begin()) {
            colors.insert(item);
        }
        else {
            it--;
            colors.erase(it);
            colors.insert(item);
        }
    }
    cout << colors.size() << endl;
    return 0;
}

