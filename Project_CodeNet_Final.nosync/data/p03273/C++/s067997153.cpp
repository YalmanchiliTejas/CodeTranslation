#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
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
    string skip = string(w, '.');
    vector<bool> iSkip(h, false);
    vector<bool> jSkip(w, false);
    vector<string> a(h);
    
    // 行が全て白じゃないかチェック
    rep(i, h){
        cin >> a[i];
        if(a[i] == skip) iSkip[i] = true;
    }

    // 列が全て白じゃないかチェック
    rep(j, w){
        bool tmp = true;
        rep(i, h){
            if(a[i][j] == '#'){
                tmp = false;
                break;
            }
        }
        if(tmp) jSkip[j] = true;
    }

    // 白のマスを詰めて出力
    rep(i, h){
        if(iSkip[i] == true) continue;
        rep(j, w){
            if(jSkip[j] == true) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}