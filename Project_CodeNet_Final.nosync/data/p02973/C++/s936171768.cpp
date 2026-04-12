#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}
 
int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    multimap<int, int> mp;
    int color = 0;
    rep(i, N) {
        if(mp.empty()) {
            mp.insert({-A[i], color});
            continue;
        }
        auto it = mp.upper_bound(-A[i]);
        if(it == mp.end()) {
            mp.insert({-A[i], ++color});
        } else {
            mp.insert({-A[i], it->second});
            mp.erase(it);
        }
    }
    cout << color + 1 << "\n";
}
