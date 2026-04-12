#include <bits/stdc++.h>

#define mod 1000000007

#define rep(i, n) for(ll i=0; i<=n; ++i)

using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
 
int main(void){
	
	ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;

    ll ans = INF;

    rep(i, 100000){
        ans = min(i*C + max(0ll, X-i)*A + max(0ll, Y-i)*B, ans);
    }

    cout << ans << endl;
	
	return 0;
}