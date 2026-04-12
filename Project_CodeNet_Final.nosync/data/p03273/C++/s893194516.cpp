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

    int h, w;
    cin>>h>>w;
    vector<string> grid(h);
    cin>>grid;

    vi ho, ve;
    rep(i, h) {
        bool wh = true;
        rep(j, w) {
            if (grid[i][j] == '#') wh = false;
        }
        if (wh) ho.push_back(i);
    }
    rep(j, w) {
        bool wh = true;
        rep(i, h) {
            if (grid[i][j] == '#') wh = false;
        }
        if (wh) ve.push_back(j);
    }
    rep(i, h) {
        if (find(rng(ho), i) != ho.end()) continue;
        rep(j, w) {
            if (find(rng(ve), j) != ve.end()) continue;
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}