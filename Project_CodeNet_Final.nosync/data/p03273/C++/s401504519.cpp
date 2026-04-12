#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> d_h(h), d_w(w);
    rep(i, h){
        rep(j, w){
            cin >> a.at(i).at(j);
            if(a.at(i).at(j) == '#'){
                d_h.at(i) = true;
                d_w.at(j) = true;
            }
        }
    }

    rep(i, h){
        if(!d_h.at(i)) continue;
        rep(j, w){
            if(!d_w.at(j)) continue;
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}