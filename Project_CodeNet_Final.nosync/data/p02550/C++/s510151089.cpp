#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int mod = 1000000007;
const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

void yes(){
    cout << "Yes" << endl;
}

void no (){
    cout << "No" << endl;
}

ll cel (ll a, ll b){
    if (a % b == 0) return a / b;
    else return a / b + 1;
}

ll gcds(ll a, ll b){
    ll c = a % b;
    while (c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() {
    ll n, x, mo; cin >> n >> x >> mo;
    ll ans = x;
    vector<ll> ar = {x};
    map<ll,int> m;
    m[x] = 0;
    ll haba = 0; int le = 0; int cnt = 0;
    bool t = false;
    rep(i,n-1){
        ll ima = ar[i] * ar[i] % mo;
        if (m.find(ima) == m.end()){
            m[ima] = i+1;
            ar.emplace_back(ima);
            ans += ima;
        }
        else {
            haba = i+1 - m[ima];
            le = m[ima];
            t = true;
            cnt = i;
            break;
        }
    }
    if (t){
        ll k = (n-1-cnt) / haba;
        ll wa = 0LL;
        rep(i,haba) wa += ar[le+i];
        ans += k * wa;
        rep(i,(n-1-cnt) % haba) ans += ar[le+i];
        cout << ans << endl;
    }
    else cout << ans << endl;
}