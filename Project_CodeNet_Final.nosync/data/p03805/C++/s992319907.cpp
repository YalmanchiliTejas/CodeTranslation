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
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int n;
vvi to;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m;
    cin>>n>>m;
    to = vvi(n, vi(n));
    rep(i, m) {
        int v1, v2;
        cin>>v1>>v2; v1--; v2--;
        to[v1][v2] = 1;
        to[v2][v1] = 1;
    }
    vi perm;
    rep(i, n) perm.push_back(i);
    ll cnt = 0;
    do {
        bool f = true;
        rep(i, n - 1) {
            if (!to[perm[i]][perm[i + 1]]) f = false;
        }
        if (f) cnt++;
    } while(next_permutation(rng(perm)) && perm[0] == 0);

    cout<<cnt<<endl;
}