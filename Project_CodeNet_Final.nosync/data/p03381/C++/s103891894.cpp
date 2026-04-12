#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep2(i,n) REP(i,1,n+1)
#define rep3(i,n) REP(i,0,n+1)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define repll(i,n) REPLL(i,0,n)
#define repll2(i,n) REPLL(i,1,n+1)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define Size(s) (int) s.size()

//------------------------------------------------------

int main() {
    int n;
    cin >> n;
    vector<pii> v;

    rep(i, n) {
        int a;
        cin >> a;
        v.push_back(MP(a, i));
    }

    sort(v.begin(), v.end());

    int mid = v[n / 2].first;

    vector<pii> ans;

    for (auto i : v) {
        if (i.first < mid) {
            ans.push_back(MP(i.second, v[n / 2].first));
        } else {
            ans.push_back(MP(i.second, v[(n - 1) / 2].first));
        }
    }

    sort(ans.begin(), ans.end());

    for (auto x : ans) cout << x.second << endl;

    return 0;
}