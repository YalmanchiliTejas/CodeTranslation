#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
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
    vvint ct(n,vint(26,0));
    rep(i,n) {
        string s; cin >> s;
        rep(j,s.size()) ct[i][s[j]-'a']++;
    }
    vint tmp(26);
    rep(i,26) {
        int count = inf;
        rep(j,n) count = min(count,ct[j][i]);
        tmp[i] = count;
    }
    rep(i,26) {
        rep(j,tmp[i]) cout << char(i+'a');
    }
    cout << endl;
}