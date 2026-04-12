#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, 0, H) cin >> a[i];
    vector<bool> row(H, false), col(W, false);
    rep(h, 0, H){
        bool f = false;
        rep(w, 0, W){
            if(a[h][w] == '#') f = true;
        }
        row[h] = f;
    }
    rep(w, 0, W){
        bool f = false;
        rep(h, 0, H){
            if(a[h][w] == '#') f = true;
        }
        col[w] = f;
    }
    rep(h, 0, H){
        if(!row[h]) continue;
        rep(w, 0, W){
            if(!col[w]) continue;
            cout << a[h][w];
        }
        cout << endl;
    }
    return 0;
}