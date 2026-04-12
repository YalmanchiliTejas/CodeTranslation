#include <iostream>
using namespace std;
typedef long long ll;
ll n, a[55], sho[55], ans;
int main(void){
    // Your code here!
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> a[i];
    while(true){
        ll shosum = 0;
        for (ll i = 0; i < n; i++){
            sho[i] = a[i] / n;
            shosum += a[i] / n;
            a[i] %= n;
        }
        for (ll i = 0; i < n; i++){
            a[i] += shosum - sho[i];
        }
        ans += shosum;
        if (shosum == 0) break;
    }
    cout << ans << endl;
}
