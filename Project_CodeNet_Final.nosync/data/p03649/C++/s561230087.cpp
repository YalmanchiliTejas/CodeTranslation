#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin>>n;
    vl as(n);
    cin>>as;

    ll l = -1, r = LINF;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll temp = m;
        bool f = true;
        rep(i, n) {
            ll c = (as[i] + m - n + 1) / (n + 1);
            if ((as[i] + m - n + 1) % (n + 1)) c++;
            if (temp >= c) temp -= c;
            else {
                f = false;
                break;
            }
        }
        if (f) r = m;
        else l = m;
    }

    ll u = max(0ll, r - 100000);
    for (ll m = u; m < r; ++m) {
        ll temp = m;
        bool f = true;
        rep(i, n) {
            ll d = (as[i] + m - n + 1);
            ll c = d / (n + 1);
            if (d >= 0 && d % (n + 1)) c++;
            c = max(c, 0ll);
            if (temp >= c) temp -= c;
            else {
                f = false;
                break;
            }
        }
        if (f) {
            cout<<m<<endl;
            return 0;
        }
    }
    cout<<r<<endl;
}