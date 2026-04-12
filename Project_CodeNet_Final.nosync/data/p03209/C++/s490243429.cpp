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

void yes(int n){
    cout << "Yes" << endl;
}

void no (int n){
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

vector<ll> zen(51);
vector<ll> pat(51);

ll ans (int n, ll k, ll ima){
    if (k == 0LL) return ima;
    if (n == 0) return ima + 1LL;
    if (k == 1LL) return ima;
    if (1LL < k && k < zen[n-1]+2LL) return ans(n-1,k-1LL,ima);
    if (k == zen[n-1]+2LL) return ima + pat[n-1] + 1LL;
    if (zen[n-1]+2LL < k && k < zen[n]) return ans(n-1,k-zen[n-1]-2LL,ima+pat[n-1]+1LL);
    if (k == zen[n]) return ima + pat[n]; 
}

int main() {
    int n; cin >> n;
    ll k; cin >> k;
    zen[0] = 1LL;
    pat[0] = 1LL;
    rep(i,50){
        zen[i+1] = 2LL * zen[i] + 3LL;
        pat[i+1] = 2LL * pat[i] + 1LL;
    }
    cout << ans(n,k,0LL) << endl;
}