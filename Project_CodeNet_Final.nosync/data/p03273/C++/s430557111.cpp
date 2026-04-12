#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int h, w; cin >> h >> w;
    map<int,int> x, y;
    char a[w][h];

    rep(i,h) rep(j,w) cin >> a[j][i];

    rep(i,h) rep(j,w) if(a[j][i] == '#') break; else if(j == w-1) y[i]++;
    rep(i,w) rep(j,h) if(a[i][j] == '#') break; else if(j == h-1) x[i]++;

    rep(i,h){
        rep(j,w) if(x[j] == 0 && y[i] == 0) cout << a[j][i];
        if(y[i] == 0) cout << endl;
    }
}