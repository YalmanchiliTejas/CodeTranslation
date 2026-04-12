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

ll s[51];
ll t[51];

ll calc(ll n, ll x) {
    if(x == 0) return 0;
    if(n == 0) return 1;
    if(s[n-1] + 2 <= x) {
        return t[n-1] + 1 + calc(n-1, x - s[n-1] - 2); 
    }
    else {
        return calc(n-1, x-1);
    }
}

int main(){
    ll n, x;
    cin >> n >> x;
    s[0] = 1;
    REP(i, 1, 51) s[i] = s[i-1]*2 + 3;
    t[0] = 1;
    REP(i, 1, 51) t[i] = t[i-1]*2 + 1;
    cout << calc(n, x) << endl;
    return 0;
}