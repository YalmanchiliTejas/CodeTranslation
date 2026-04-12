#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
    int h,w;cin>>h>>w;
    vector<bool> hv(h, false), wv(w, false);
    vector<vector<char>> a(h, vector<char>(w));
    rep(i,h) {
        rep(j,w) {
            char x;cin>>x;
            if(x=='#') {
                hv.at(i)=true;
                wv.at(j)=true;
            }
            a.at(i).at(j)=x;
        }
    }
    rep(i,h) {
        bool f = false;
        rep(j,w) {
            if(hv.at(i)&&wv.at(j)) {
                cout<<a.at(i).at(j);
                f = true;
            }
        }
        if(f) cout<<endl;
    }
}

