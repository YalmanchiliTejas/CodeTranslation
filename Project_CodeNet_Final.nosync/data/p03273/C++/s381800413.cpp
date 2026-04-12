#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    vector<bool> valH(H, false), valW(W, false);
    rep(h, 0, H) cin >> a[h];
    rep(h, 0, H){
        bool f = false;
        rep(w, 0, W){
            if(a[h][w] == '#') f = true;
        }
        if(f) valH[h] = true;
    }
    rep(w, 0, W){
        bool f = false;
        rep(h, 0, H){
            if(a[h][w] == '#') f = true;
        }
        if(f) valW[w] = true;
    }
    rep(h, 0, H){
        if(!valH[h]) continue;
        rep(w, 0, W){
            if(!valW[w]) continue;
            cout << a[h][w];
        }
        cout << endl;
    }
    return 0;
}