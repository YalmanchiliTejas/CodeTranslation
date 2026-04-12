#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;

int main(){
    ll N;    cin >> N;
    VL a(N); 
    ll sum = 0;
    rep(i,0,N){
        cin >> a[i];
        sum += a[i];
    }

    ll ans = 0;
    rep(i,0,N-1){
        sum = sum - a[i];
      	//cout << sum << endl;
        ans += (a[i]%MOD) * (sum%MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}