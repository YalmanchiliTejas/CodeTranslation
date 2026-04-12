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
    int N; cin >> N;
    vll A(N);
    rep(i,N) cin >> A[i];
    ll sum = 0;
    rep(i,N) sum += A[i];
    ll x = sum - N*(N-1);
    ll l = 0, r = inf_l;
    while (r - l > 1) {
        ll mid = (r+l) / 2;
        auto f = [&](ll y) {
            sum = 0;
            rep(i,A.size()) {
                sum += max((A[i]+x-y+N)/(N+1),(ll)0);
            }
            return sum <= x;
        };
        if (f(mid)) r = mid;
        else l = mid;
    }
    ll ans = 0;
    for (ll i = x - N; i <= x; i++) {
        sum = 0;
        rep(j,A.size()) {
            sum += max((A[j]+i-r+N)/(N+1),(ll)0);
        }
        if (sum == i) {
            ans += i;
            rep(j,A.size()) {
                A[j] = A[j] + i - max((A[j]+i-r+N)/(N+1),(ll)0)*(N+1);
            }
            break;
        }
    }
    sort(all(A));
    while (true) {
        if (A.back() < N) break;
        ans++;
        rep(i,A.size()-1) A[i]++;
        A.back() -= N;
        sort(all(A));
    }
    cout << ans << endl;
}