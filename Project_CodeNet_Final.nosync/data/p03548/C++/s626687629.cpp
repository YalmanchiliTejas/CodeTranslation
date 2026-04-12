#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll X,Y,Z; cin >> X >> Y >> Z;
    if(X/(Y+Z)*(Y+Z) + Z <= X) cout << X/(Y+Z) << endl;
    else cout << X/(Y+Z)-1 << endl;
    return 0;
}
