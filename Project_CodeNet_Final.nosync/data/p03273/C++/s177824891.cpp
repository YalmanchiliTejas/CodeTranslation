#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll H, W;
    cin >> H >> W;
    VS w(H), h(W);
    rep(i, 0, H){
        cin >> w[i];
        rep(j, 0, W) h[j].push_back(w[i][j]);
    }
    string sh, sw;
    rep(i, 0, H) sh.push_back('.');
    rep(i, 0, W) sw.push_back('.');
    vector<bool> vh(H, true), vw(W, true);
    rep(i, 0, H){
        if(w[i] == sw) vh[i] = false;
    }
    rep(i, 0, W){
        if(h[i] == sh) vw[i] = false;
    }
    rep(i, 0, H){
        rep(j, 0, W){
            if(vh[i] && vw[j]) cout << w[i][j];
        }
        if(vh[i]) cout << endl;
    }
    return 0;
}