#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w));
    rep(i,h) {
        rep(j,w) {
            cin >> a.at(i).at(j);
        }
    }

    vector<bool> wdel(w,false);
    rep(j,a.at(0).size()) {
        int wpos=j;
        rep(i,a.size()) {
            if (a.at(i).at(j)=='#') {
                wpos=-1;
                break;
            }
        }
        if (wpos != -1) wdel.at(wpos)=true;
    }

    vector<bool> hdel(h,false);
    rep(i,a.size()) {
        int hpos=i;
        rep(j,a.at(0).size()) {
            if (a.at(i).at(j)=='#') {
                hpos=-1;
                break;
            }
        }
        if (hpos != -1) hdel.at(hpos)=true;
    }

    rep(i,a.size()) {
        if (hdel.at(i)) continue;
        rep(j,a.at(0).size()) {
            if (wdel.at(j)) continue;
            cout << a.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}