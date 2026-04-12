class in{struct It{int it;const bool rev;explicit constexpr It(int it_, bool rev=false):it(it_),rev(rev){}int operator*(){return it;}bool operator!=(It& r){return it!=r.it;}void operator++(){rev?--it:++it;}};const It i,n;public:explicit constexpr in(int n):i(0),n(n<0?0:n){}explicit constexpr in(int i,int n):i(i,n<i),n(n){}const It& begin(){return i;}const It& end(){return n;}};

#include <bits/stdc++.h>
using namespace std;

bool used[10][10];
int h, w;
vector<string> fld;
const int dx[2] = {0, 1}, dy[2] = {1, 0};
bool dfs(int cx, int cy) {
    if(cx == w - 1 && cy == h - 1) {
        bool res = true;
        for(int i : in(h)) for(int j : in(w))
          if(fld[i][j] == '#' && !used[i][j])
            res = false;
        return res;
    }
    bool ok = false;
    for(int i : in(2)) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if(fld[ny][nx] == '#') {
            used[ny][nx] = true;
            ok |= dfs(nx, ny);
            used[ny][nx] = false;
        }
    }
    return ok;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    fld.resize(h);
    for(auto& x : fld) cin >> x;
    bool ans = false;
    used[0][0] = true;
    cout << (dfs(0, 0) ? "Possible" : "Impossible") << endl;
    return 0;
}