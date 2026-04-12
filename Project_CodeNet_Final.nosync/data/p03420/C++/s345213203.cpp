#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using P = pair<ll,ll>;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll n,k;cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    ll res=0;
    for(ll i=1;i<=n;i++){
        if(i<=k) continue;
        res+=(n/i)*(i-k);
        if(n%i>=k) res+=(n%i)-k+1;
    }
    cout<<res<<endl;
}
