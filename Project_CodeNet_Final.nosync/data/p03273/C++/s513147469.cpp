#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD =1e9+7;
using ll=long long;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h){
        cin >> a[i];
    }
    // 縦
    set<int> memotate;
    rep(j,w){
        bool J = 1;
        rep(i,h){
            if(a[i][j] == '#') {
                J = 0;
                break;
            }
        }
        if(J) memotate.insert(j);
    }
    //横
    set<int> memoyoko;
    rep(i,h){
        bool J = 1;
        rep(j,w){
            if(a[i][j] == '#') {
                J = 0;
                break;
            }
        }
        if(J) memoyoko.insert(i);
    }

    //結果
    rep(i,h){
        if(memoyoko.count(i)) continue;
        rep(j,w){
            if(memotate.count(j)) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}