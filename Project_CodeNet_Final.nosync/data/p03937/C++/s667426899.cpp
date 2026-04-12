#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    int cnt = 0;
    rep(i,h)rep(j,w){
        if(a[i][j] =='#') cnt++;
    }
    if(cnt == h+w-1) cout << "Possible" <<endl;
    else cout << "Impossible" << endl;
    return 0;
}