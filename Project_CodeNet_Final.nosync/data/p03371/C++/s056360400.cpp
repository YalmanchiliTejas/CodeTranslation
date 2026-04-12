#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1e18;
    rep(i, 2e5+10) {
        ll tmp = i*c;
        tmp += max(0LL, x - i/2) * a;
        tmp += max(0LL, y - i/2) * b;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}