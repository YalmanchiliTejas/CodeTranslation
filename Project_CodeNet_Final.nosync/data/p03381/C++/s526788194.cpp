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
    int n;
    cin >> n;
    vector<pii> v(n);
    rep(i, n) {
        cin >> v[i].fi;
        v[i].se = i;
    }
    sort(all(v));
    vector<int> ans(n);
    rep(i, n) {
        if(i < n/2) {
            ans[v[i].se] =  v[n/2].fi;
        }
        else {
            ans[v[i].se] =  v[n/2-1].fi;
        }
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}