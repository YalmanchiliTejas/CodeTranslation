#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<ll> a;
vector<ll> p;

ll f(int n, ll x) {
    if (n == 0) return 1;
    if (x == 1) return 0;
    if (x <= a[n-1]+1) return f(n-1,x-1);
    if (x == a[n-1]+2) return p[n-1]+1;
    if (x <= 2*a[n-1]+2) return p[n-1]+1+f(n-1,x-a[n-1]-2);
    if (x == 2*a[n-1]+3) return 2*p[n-1]+1;
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    a.resize(n+1);
    a[0] = 1;
    rep(i,n) {
        a[i+1] = a[i]*2+3;
    }
    p.resize(n+1);
    p[0] = 1;
    rep(i,n) {
        p[i+1] = p[i]*2+1;
    }
    ll ans = f(n,x);
    cout << ans << endl;
    return 0;
}