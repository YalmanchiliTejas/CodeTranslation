#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll h, w; cin >> h >> w;
    vector<string> lab(h);
    rep(i, h) cin >> lab[i];
    vvi chk(h, vi(w, 0));

    // 右に動ける場合は右に移動し、行けない場合は下に行く
    queue<pair<ll, ll>> que;
    que.push(make_pair(0, 0));
    chk[0][0] = 1;
    while(que.size()){
        auto pos = que.front();
        que.pop();
        ll x = pos.second;
        ll y = pos.first;
        if(x+1 < w && lab[y][x+1] =='#'){
            que.push(make_pair(y, x+1));
            chk[y][x+1]=1;
        }
        else if(y+1 < h && lab[y+1][x] =='#'){
            que.push(make_pair(y+1, x));
            chk[y+1][x]=1;
        }
    }

    // 通った箇所と'#'の箇所が同一かチェック
    bool ans = true;
    rep(i, h){
        rep(j, w){
            if(lab[i][j] == '#' && chk[i][j] == 0) ans = false;
        }
    }

    cout << (ans ? "Possible" : "Impossible") << endl;
}