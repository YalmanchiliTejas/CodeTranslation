#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

ll n, k, m;
map<vi, ll> dp[301];

void debug (vector<int> v) {
    rep(i,v.size()) cout << v[i] << " ";
    cout << endl;
}

int main() {
    cin >> n >> k >> m;
    dp[0][vi()] = 1;
    for (int i = 0; i < n; i++) {
        for (auto it = dp[i].begin(); it != dp[i].end(); it++) {
            vi vec = (*it).first;
            ll val = (*it).second;
            ll len = vec.size();
            //cout << i << ": ";
            //debug(vec);
            rep(_,len+1) {
                if (k >= n || vec.size() < k-1) {
                    vec.push_back(0);
                    rep(j,vec.size()) vec[j]++;
                    if (vec[0] <= k) {
                        dp[i+1][vec] = (dp[i+1][vec] + val) % m;
                    }
                    rep(j,vec.size()) vec[j]--;
                    vec.pop_back();
                }
                
                if (vec.size() > 0) {
                    vec.erase(vec.begin());
                    rep(j,vec.size()) vec[j]++;
                }
            }
        }
    }
    ll ans = 0;
    for (auto it = dp[n].begin(); it != dp[n].end(); it++) {
        ans = (ans + (*it).second) % m;
    }
    cout << ans << endl;
}

