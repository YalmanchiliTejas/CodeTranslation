#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int H,W;
    cin >> H >> W;
    vector<string> f(H);
    set<int> r,c;
    rep(i,H) {
        cin >> f.at(i);
        bool x = 1;
        rep(j,W)
            if(f.at(i).at(j) == '#')
                x = 0;
        if(x)
            c.insert(i);
    }
    
    rep(i,W) {
        bool x = 1;
        rep(j,H)
            if(f.at(j).at(i) == '#')
                x = 0;
        if(x)
            r.insert(i);
    }

    rep(i,H) {
        if(c.count(i))
            continue;
        rep(j,W)
            if(!r.count(j))
                cout << f.at(i).at(j);
        cout << endl;
    }
}