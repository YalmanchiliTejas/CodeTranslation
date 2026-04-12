#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll MOD = 1000000007;
    ll ans = 0;
    ll sum = 0;
    rep(i,n){
        ans += sum * a[i];
        ans %= MOD;
        sum += a[i];
        sum %= MOD;
    }
    cout << ans << endl;
    return 0;
}


