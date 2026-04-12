#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rREP(i, k, n) for (int i = (int)(n)-1; i >= k; i--)

#define fi first
#define se second

#define vi vector<int>
#define pb push_back
#define mp make_pair

#define pcnt __builtin_popcount

typedef long long ll;

const int inf = 100100100;
const int MOD = (int) 1e9 + 7;
const double EPS = 1e-9;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b;
        return 1;
    }
    return 0;
}

template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b;return 1; }return 0; }
int main() {
    int h,w;
    cin >> h >> w;
    string s[110];
    rep(i,h){
        cin >> s[i];
    }
    //縦列での圧縮を考える
    bool uy[110] ={};
    bool ux[110] = {};
    rep(x,w){
        int y = 0;
        for(;y<h;y++){
            if(s[y][x]=='#') break;
        }
        if(y==h) ux[x] = true;
    }
    rep(y,h){
        int x = 0;
        for(;x<w;x++){
            if(s[y][x]=='#') break;
        }
        if(x==w) uy[y] = true;
    }
    rep(y,h){
        if(uy[y]) continue;
        rep(x,w){
            if(ux[x]) continue;
            cout << s[y][x];
        }
        cout << endl;
    }
    return 0;
}