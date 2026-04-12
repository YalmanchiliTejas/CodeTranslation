#include <iostream>
#include <vector>
using namespace std;
using LL = long long int;
LL inf = 1000000007;
int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    LL ans = 0;
    LL uhen = 0;
    for(int i = 2;i <= n;i++){
        uhen += a[n - i + 1];
        uhen %= inf;
        ans += (a[n-i] * uhen) % inf;
        ans %= inf;
    }
    cout << ans;


    return 0;
}
