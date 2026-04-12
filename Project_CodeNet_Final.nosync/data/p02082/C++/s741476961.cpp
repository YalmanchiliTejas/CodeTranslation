#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP2(i,m,n) for (int i=m;i<(n);i++)
typedef long long ll;

void solve() {
    ll p,q,s,t,y,M;
    cin >> s >> t >> p >> q >> M >> y;
    cout << (s ^ t ^ y) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

