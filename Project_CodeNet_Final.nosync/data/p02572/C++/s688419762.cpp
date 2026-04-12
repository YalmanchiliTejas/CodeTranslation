#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void debugF(ostream &os) {os << endl;}
template <typename Head, typename... Tail>
void debugF(ostream &os, Head H, Tail... T) { os << " " << H; debugF(os, T...); }
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debugF(cout, __VA_ARGS__)
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); os << (i>0 ? " ":"") << v[i++]); return os;}

ll mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, i;
    cin >> n;
    ll ans = 0, pre = 0;
    for(i=0;i<n;i++){
        ll a; cin >> a;
        ans += (a*pre)%mod;
        ans %= mod;
        pre += a;
        pre %= mod;
    }
    cout << ans << "\n";
    return 0;
}