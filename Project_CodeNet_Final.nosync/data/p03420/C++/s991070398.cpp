#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    if(k==0){
        cout << n*n << endl;
        return 0;
    }
    for(ll i=1; i<=n; i++){
        if(i-1 < k) continue;
        ans += n/i * (i-1-k+1);
        ans += max(0ll , n%i - k + 1 );
    }
    cout << ans << endl;
    return 0;
}