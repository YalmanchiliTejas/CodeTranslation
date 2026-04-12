#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define min(a, b) ((a) < (b)? (a):(b))
#define max(a, b) ((a) > (b)? (a):(b))
#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)
#define abs(a) ((a) < (0)? -(a):(a))
#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)
#define pb push_back


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    ll ans = 100000000000;
    for(ll nc=0; nc<=2*max(x, y); nc+=2) {
        int na = max(0, x - nc / 2);
        int nb = max(0, y - nc / 2);
        ans = min(ans, a*na+b*nb+c*nc);
    }

    cout << ans << endl;
}
