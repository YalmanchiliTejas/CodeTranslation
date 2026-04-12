#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<int> r(h), c(w);
    rep(i,h){
        rep(j,w) {
            if(a[i][j]=='#') {
                r[i] = 1;
                c[j] = 1;
            }
        }
    }
    rep(i,h){
        if(r[i]!=1) continue;
        rep(j,w){
            if(c[j]!=1) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}