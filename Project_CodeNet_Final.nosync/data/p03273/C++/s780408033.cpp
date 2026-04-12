#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(auto& x : s)
        cin >> x;
    vector<int> a(h, 0), b(w, 0);
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j){
            a[i] += (s[i][j] == '#');
            b[j] += (s[i][j] == '#');
        }
    for(int i = 0; i < h; ++i){
        if(!a[i])
            continue;
        for(int j = 0; j < w; ++j){
            if(!b[j])
                continue;
            cout << s[i][j];
        }
        cout << endl;
    }
}
