#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = 3.141592653589793;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REPR(i,a,b) for(ll i=b;i>=a;i--)
#define repr(i,n) REPR(i,0,n)
#define All(v) (v).begin(), (v).end()
#define Pb push_back

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,ans; cin >> n;
    ans = n * 800;
    ans -= 200 * (n/15);
    cout << ans << "\n";
    return 0;
}