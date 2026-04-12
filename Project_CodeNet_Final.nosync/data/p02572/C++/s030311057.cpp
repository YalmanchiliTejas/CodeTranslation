#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
const ll MOD = 1000000007;
void Main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    For(i,0,n) cin >> a[i];
    ll sm = accumulate(ALL(a), 0LL);
    sm %= MOD;
    sm *= sm;
    sm %= MOD;
    ans += sm;
    for(auto i:a){
        ans -= i * i % MOD;
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
    }
    ans *= 500000004;
    ans %= MOD;
    cout << ans << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}