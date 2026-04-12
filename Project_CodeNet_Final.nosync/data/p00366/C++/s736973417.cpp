#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> V;
typedef pair<ll,ll> P;
typedef map<ll,ll> M;

#define REP(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define FOR(i,j,n) for(ll (i) = (j); (i) < (n); ++(i))
#define REPR(i,n) for(ll (i) = (n); (i) >= 0; --i))


signed main(){
    ll n;
    cin >> n;
    V a(n);
    for(auto& xx : a)
        cin >> xx;
    ll ma = *max_element(a.begin(), a.end());
    ll nowma = ma;
    V yak;
    ll sq = sqrt(ma) + 1;
    FOR(i, 1, sq){
        if(ma % i == 0){
            yak.push_back(i);
            yak.push_back(ma / i);
        }
    }
    sort(yak.begin(), yak.end());
    ll ans = 0;
    for(auto xx : a){
        ans += (*lower_bound(yak.begin(), yak.end(), xx)) - xx;
    }
    cout << ans << endl;
}

