#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REP2(i,x,n) for(ll i=x; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> maps(H);
    
    vector<bool> ws(W, false);
    vector<bool> hs(H, false);

    for ( ll i = 0; i < H; ++ i ){
        cin >> maps[i];
        
        if ( maps[i].find('#') != string::npos ){
            hs[i] = true;
        }
        for ( ll j = 0; j < maps[i].size(); ++ j ){
            ws[j] = ws[j] | (maps[i][j] == '#');
        }
    }

    for ( ll i = 0; i < H; ++ i ){
        if ( !hs[i] )   continue;
        for ( ll j = 0; j < W; ++ j ){
            if ( !ws[j] )   continue;
            cout << maps[i][j];
        }
        cout << endl;
    }
    return 0;
}