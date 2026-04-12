#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define all(v) v.begin(), v.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pll pair<long long, long long>
#define pb emplace_back
#define mp make_pair
#define mt make_tuple
#define vc vector<char>
#define vvc vector<vc>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
template <class T>bool chmax(T &a, const T &b){if (a < b){a = b;return 1;}return 0;}
template <class T>bool chmin(T &a, const T &b){if (b < a){a = b;return 1;}return 0;}
//snippets:tmp,cl,cvl,cs,co,coy,con,cov,setp

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x;
    cin >> x;
    if(x>=30) cout << "Yes" << endl;
    else cout << "No" << endl;
}