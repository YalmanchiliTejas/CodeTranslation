#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(auto &l: a) cin >> l;

    vector<vector<ll>> d(h, vector<ll>(w));

    ll s = 0;
    for(auto &l: a)
        for(auto &c: l)
            s += c == '#';

    queue<pair<ll,ll>> q;
    d[0][0] = 1;
    q.push({0,0});
    while(!q.empty()) {
        ll i, j;
        tie(i, j) = q.front(); q.pop();
        if(i==h-1 && j==w-1 && d[i][j] == s) {
            cout << "Possible" << endl;
            return 0;
        }
        if(i+1<h && a[i+1][j] == '#' && d[i+1][j] <= d[i][j]) d[i+1][j] = d[i][j] + 1, q.push({i+1,j});
        if(j+1<w && a[i][j+1] == '#' && d[i][j+1] <= d[i][j]) d[i][j+1] = d[i][j] + 1, q.push({i,j+1});
    }
            cout << "Impossible" << endl;
            return 0;
}
