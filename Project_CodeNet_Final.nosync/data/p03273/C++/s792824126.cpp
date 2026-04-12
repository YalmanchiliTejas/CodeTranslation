#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const int MOD = 1000000007; 

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> mass(h, vector<char>(w, '.')); 
    set<int> ih, iw; 
    rep(i, h) {
        rep(j, w) {
            char c; cin >> c;
            if (c == '#') {
                mass[i][j] = c;
                ih.insert(i);
                iw.insert(j);
            }
        }
    }
    for(int i : ih) {
        for (int j : iw) {
            cout << mass[i][j];
        }
        cout << endl;
    }
    return 0;
}