#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////
Vl a, p;
ll n, x; 

ll f(ll n, ll x){
    if(n == 0){
        if(x <= 0) return 0;
        else return 1;
    }else if(x <= 1 + a[n-1]){
        return f(n-1, x-1);
    }else{
        return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
    }
}

int main() {
    cin >> n >> x;
    a.resize(n);
    p.resize(n);
    a[0] = 1; p[0] = 1;
    rep(i, 1, n){
        a[i] = a[i-1]*2 + 3; //thickness
        p[i] = p[i-1]*2 + 1; //patty
    }

    co(f(n, x));

    return 0;
}
