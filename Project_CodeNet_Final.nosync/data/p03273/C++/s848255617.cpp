#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = 3.141592653589793;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REPR(i,a,b) for(ll i=b;i>=a;i--)
#define repr(i,n) REPR(i,0,n)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
#define m_p make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h,w,cnt,flag;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    vector<ll> remh(h,0),remw(w,0);
    rep(i,h){
        cnt = 0;
        rep(j,w){
            if(a[i][j]=='.') cnt++;
        }
        if(cnt==w) remh[i] = 1;
    }
    rep(i,w){
        cnt = 0;
        rep(j,h){
            if(a[j][i]=='.') cnt++;
        }
        if(cnt==h) remw[i] = 1;
    }
    rep(i,h){
        if(remh[i]==1) continue;
        rep(j,w){
            if(remw[j]==0) cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}