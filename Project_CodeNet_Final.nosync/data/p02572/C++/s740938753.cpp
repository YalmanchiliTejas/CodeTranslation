#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(1);

    rep(i, n){
        cin >> a[i];
        b.push_back((b[i] + a[i]) % MODN);
    }

    ll ans = 0;

    rep(i, n){
        ll sum = b[n] - b[i + 1];
        if(sum < 0) sum += MODN;

        sum = sum % MODN;
        ans = (ans + (a[i] * sum) % MODN) % MODN; 
    }

    cout << ans << endl;

    
    return 0;

}
