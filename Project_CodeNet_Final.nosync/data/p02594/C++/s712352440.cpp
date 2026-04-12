#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1e18;
//const ll MOD = 1e9+7;
//const double pi = 3.14159265358979;
using vl = vector<ll>;
# define rep(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(ll i=((ll)(n)-1); i>=0; --i)
# define rreps(i, n) for(ll i=((ll)(n)); i>0; --i)
# define all(x) (x).begin(), (x).end()
 
ll n;
ll Main() {
    cin >> n;
    ll ans = 0;
    
    if(n>=30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
 
int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
