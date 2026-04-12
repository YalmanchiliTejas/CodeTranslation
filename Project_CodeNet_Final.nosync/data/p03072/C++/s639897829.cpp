#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <new>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;
using Graph = vector<vector<ll>>;

#define rep(i, N) for (ll i = 0; i < (ll)(N); ++i)
#define ALL(a) (a).begin(),(a).end()

const ll inf = 1e18+7;
const ll mod = 1e9+7;

ll GetDigit(ll num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

int main(){
    ll N,ans=1;
    cin >> N;
    vector<ll> H(N,0);
    rep(i,N) cin >> H[i];
    ll ma=H[0];
    for(ll i=1;i<N;i++){
        ma = max(ma,H[i]);
        if(ma<=H[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
