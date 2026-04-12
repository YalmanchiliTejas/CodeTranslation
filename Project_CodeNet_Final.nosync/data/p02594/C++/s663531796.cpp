#pragma GCC optimize ("-Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(a) (long long)a.size()
#define all(a) a.begin(), a.end()
#define reset(a, n) a.clear(), a.resize(n)
#ifndef ONLINE_JUDGE
#define cin ___in
#endif
std::ifstream ___in("input.in");
using namespace std;
using ll = long long;
typedef pair<ll, ll> pi;
typedef vector<ll> vec;
typedef vector<vector<ll> > vvec;
typedef vector<pair<ll, ll> > vecpi;
typedef vector<vector<pair<ll, ll> > > vvecpi;
typedef set<ll> seti;
typedef set<pair<ll, ll> > setpi;
typedef multiset<ll> mseti;
typedef multiset<pair<ll, ll> > msetpi;
typedef map<ll, ll> mpi;

static const bool tc = 0;
static const ll mod = LLONG_MAX - 24;

void solve() {
        ll x;
        cin >> x;
        if(x >= 30) {
                cout << "Yes";
        }
        else {
                cout << "No";
        }
}

int main() {
        srand(time(0));
        int T = 1;
        if(tc) cin >> T;
        for(int i = 1; i <= T; ++i) {
                #ifndef ONLINE_JUDGE
                cout << "----- " << i << " -----\n";
                #endif
                solve();
        }
        return 0;
}
