#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
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

vector<ll> len;
vector<ll> pat;

// lev = level, x = rest
ll dfs(ll lev, ll x) {
    ll ret = 0;
    if (x==0) return ret;
    if (lev==0) return 1ll;

    if (len[lev-1]+1 >= x) {
        ll rest = x-1;
        ret += dfs(lev-1, rest);
    }
    else if (len[lev-1]+2 == x) {
        ret = pat[lev-1]+1;
    }
    else if (len[lev] <= x) {
        ret = pat[lev];
    }
    else {
        ret += pat[lev-1]+1;
        ll rest = x-len[lev-1]-2;
        ret += dfs(lev-1, rest);
    }

    return ret;
}

int main(int argc, char const *argv[]) {
    ll n,x; cin>>n>>x;
    len.resize(n+1); pat.resize(n+1);
    len[0] = 1;
    rep(i,n) {
        len[i+1] = len[i]*2+3;
    }
    pat[0] = 1;
    rep(i,n) {
        pat[i+1] = pat[i]*2+1;
    }

    cout << dfs(n,x) << '\n';
    return 0;
}