#include <bits/stdc++.h>
#define FOR(k,m,n) for(int(k)=(m);(k)<(n);(k)++)
#define REP(k,n) FOR((k),0,(n))
using namespace std;
typedef long long ll;
typedef vector<ll> VLL;
const int MOD=1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll k, a, b;
    cin >> k >> a >> b;

    if(a >= k){
        cout << 1 << endl;
        return 0;
    }

    ll s = a - b;
    if(s <= 0){
        cout << -1 << endl;
        return 0;
    }

    ll rate;
    ll count;
    count = (k - a) / s * 2 + 1;
    rate = a + s * ((count-1) / 2);
    if(rate == k){
        cout << count << endl;
        return 0;
    }

    cout << count + 2 << endl;
    return 0;
}