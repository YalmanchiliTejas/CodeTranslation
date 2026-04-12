#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
const ll MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n);
    sum[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        sum[i] = sum[i+1]+a[i];
        sum[i] %= MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += sum[i+1]*a[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}