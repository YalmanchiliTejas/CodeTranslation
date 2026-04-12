#pragma optimization_level 3
#include <bits/stdc++.h>
#define  f               first
#define  s               second
#define  sym(s)          s = "#" + s + "#";
#define  all(x)          (x).begin(), (x).end()
#define  alll(x,n)       x+1, x+n+1
#define  newl            cout<<"\n";
#define  foo(i,a,n)      for(ll i = (a); i <= n; i++)
#define  deb1(a)         cout<<a<<"\n";
#define  deb2(a,b)       cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)     cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  debp(a)         cout<<a.f<<" "<<a.s<<"\n";
#define  debv(a)         for(auto it: a)cout<<it<<" ";newl;
#define  debm(a)         for(auto it: a)cout<<"{"<<it.f<<","<<it.s<<"}, ";newl;
#define  deb1d(a,n)      foo(i,1,n)cout<<a[i]<<" ";newl;
#define  deb2d(a,n,m)    foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}

using namespace std;
using ll              =  long long;
using ld              =  long double;
const ll   MOD        =  1e+9 + 7;
const ll   INF        =  LLONG_MAX;
const int  N          =  (int)1e+6 + 8;

ll n, x, m, a[N], pre[N];

void brute(ll n, ll x, ll m) {
    ll p = x;
    cout << p << " ";
    for (int i = 2; i <= n; i++) {
        ll nx = p * p % m;
        cout << nx << " ";
        p = nx;
    }
    newl;
}

map<ll,ll> vis;

void MAIN(int tc) {
    cin >> n >> x >> m;
    //brute(n, x, m);

    a[1] = pre[1] = x;

    ll before = 0, p = x, k = 0;
    before += p;
    for (int i = 2; i <= 1e6; i++) {
        ll nxt = p * p % m;
        if (k == 0 && vis.find(nxt)!=vis.end()) k = i;
        if (k == 0) before += nxt;
        a[i] = nxt;
        pre[i] = pre[i-1] + a[i];
        p = nxt;
        vis[a[i]] = 1;
    }

    
    if (n <= k) {
        cout << pre[n];
        return;
    }

    ll repeat = 0, ok = 0, j = 1;
    p = a[k];
    repeat += p;

    for(int i = k; i <= n; i++, j++){
        ll nxt = p * p % m;
        if(nxt == a[k]) {
            ok = 1;
            break;
        }
        repeat += nxt;
        p = nxt;
    }

    if (ok == 0) {
        cout << before + repeat;
        return;
    }

    ll after = 0;
    ll left = (n - k + 1) % j;
    for(int i = k; i < k + left; i++){
        after += a[i];
    }

    //deb3(k, j, left);
    //deb3(before, repeat, after);
    cout << before + ((n - k + 1) / j ) * repeat + after;

}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed; cout << setprecision(10);

    int test_cases = 1;
    //cin>>test_cases;
    for (int i = 1; i <= test_cases; i++) {
        MAIN(i);
    }
}