#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

ll calc(ll n, ll x, ll m) {
    ll ansh = 0;
    vector<ll> a(n);
    a[0] = x;
    rep(i,n) a[i+1] = (a[i]*a[i])%m;
    rep(i,n) ansh += a[i];
    return ansh;
}

int main(int argc, char const *argv[]) {
    ll n,x,m; cin>>n>>x>>m;

    if (n < 20000001) {
        cout << calc(n,x,m) << '\n';
        return 0;
    }

    vector<ll> a(2000001);
    vector<int> cnt(200001, -1);
    vector<ll> c;
    ll start = 0;
    a[0] = x;
    for (int i = 0; i < 2000001; ++i) {
        a[i+1] = (a[i]*a[i])%m;
        if (cnt[a[i]] != -1) {
            start = cnt[a[i]];
            for (int j = cnt[a[i]]; j < i; ++j) {
                c.push_back(a[j]);
            }
            break;
        }
        cnt[a[i]] = i;
    }

    ll ans = 0;
    ll tmp = 0;
    ll cy = c.size();
    for (auto &&e: c) tmp += e;
    ll nn = n-start;
    ll beet = nn/cy;
    ans += tmp*beet;
    ll usi = nn%cy;
    for (int i = 0; i < usi; ++i) ans += c[i];
    for (int i = 0; i < start; ++i) ans += a[i];
    cout << ans << '\n';

    return 0;
}