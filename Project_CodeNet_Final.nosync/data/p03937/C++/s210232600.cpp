#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h)cin >> s[i];
    ll cnt = 0;
    rep(i, h)rep(j, w)if(s[i][j] == '#')cnt++;
    if(cnt-1 == h + w - 2)cout << "Possible";
    else cout << "Impossible";
}      