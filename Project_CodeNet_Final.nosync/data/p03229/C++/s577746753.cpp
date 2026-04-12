#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    ll ans = -1;
    sort(rall(a));
    queue<int> q;
    rep(i,n) q.push(a[i]);
    ll sum = 0;
    rep(i,(n-1)/2) {
        int x = q.front(); q.pop();
        sum += 2*x;
    }
    if (!(n&1)) {
        int x = q.front(); q.pop();
        sum += x;
        x = q.front(); q.pop();
        sum -= x;
    } else {
        int x = q.front(); q.pop();
        sum -= x;
        x = q.front(); q.pop();
        sum -= x;
    }
    rep(i,n/2-1) {
        int x = q.front(); q.pop();
        sum -= 2*x;
    }
    ans = max(sum,ans);
    rep(i,n) q.push(a[i]);
    sum = 0;
    rep(i,n/2-1) {
        int x = q.front(); q.pop();
        sum += 2*x;
    }
    if (!(n&1)) {
        int x = q.front(); q.pop();
        sum += x;
        x = q.front(); q.pop();
        sum -= x;
    } else {
        int x = q.front(); q.pop();
        sum += x;
        x = q.front(); q.pop();
        sum += x;
    }
    rep(i,(n-1)/2) {
        int x = q.front(); q.pop();
        sum -= 2*x;
    }
    ans = max(ans,sum);
    cout << ans << endl;
}