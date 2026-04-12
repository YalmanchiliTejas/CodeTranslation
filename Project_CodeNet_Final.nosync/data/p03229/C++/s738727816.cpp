#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    sort(a,a+n);
    ll sum1 = 0,sum2 = 0;
    ll ans = 0;
    if(n % 2 == 0){
        for(int i = 0; i < n/2; i++) {
            if(i == n/2-1) ans -= a[i];
            else ans -= 2*a[i];
        }
        for(int i = n/2; i < n; i++){
            if(i == n/2) ans += a[i];
            else ans += 2*a[i];
        }
    }else{
        for(int i = 0; i <= n/2; i++){
            if(i == n/2-1 || i == n/2) sum1 -= a[i];
            else sum1 -= 2*a[i];
        }
        for(int i = n/2+1; i < n; i++){
            sum1 += 2*a[i];
        }

        for(int i = 0; i < n/2; i++){
            sum2 -= 2*a[i];
        }
        for(int i = n/2; i < n; i++){
            if(i == n/2 || i == n/2+1){
                sum2 += a[i];
            }else{
                sum2 += 2*a[i];
            }
        }
        ans = max(sum1,sum2);
    }
    cout << ans << endl;
}