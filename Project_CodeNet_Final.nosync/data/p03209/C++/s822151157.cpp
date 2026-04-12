#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

vecl cnt(51),p(51);

void init() {
    cnt[0] = 1;
    p[0] = 1;
    for(int i = 0; i < 50; i++) {
        cnt[i+1] = 2*cnt[i]+3;
        p[i+1] = 2*p[i]+1;
        //cout << p[i+1] << " " << cnt[i+1] << endl;
    }
}

ll f(ll L, ll X) {
    //cout << L << " " << X << endl;
    //cout << cnt[L-1] << " " << p[L-1] << endl;
    if(L == 0 && X == 1)  return 0;
    if(X == 1) return 0;
    if(1 < X && X < cnt[L-1]+1) return f(L-1,X-1);
    else if(X == cnt[L-1]+1) return p[L-1];
    else if(X == cnt[L-1]+2) return p[L-1]+1;
    else if(X < 2*cnt[L-1]+2) return f(L-1,X-(cnt[L-1]+2))+p[L-1]+1;
    else if(X >= 2*cnt[L-1]+2) return 2*p[L-1]+1;
}

int main() {
    ll N,X; cin >> N >> X;
    init();
    cout << f(N,X) << endl;
}