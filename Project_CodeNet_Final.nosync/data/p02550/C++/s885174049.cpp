#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    int d[100005];
    for(int i = 0; i < m; i++) d[i] = -1;
    ll k;
    ll ans = 0;
    int i;
    for(i = 0; i < n; i++){
        if(d[x] >= 0){
            k = i - d[x];
            break;
        }
        d[x] = i;
        ans += x;
        x = x * x % m;
    }
    if(i == n){
        cout << ans << endl;
        return 0;
    }
    n -= i;
    ll s = 0;
    for(i = 0; i < k; i++){
        s += x;
        x = x * x % m;
    }
    ans += n / k * s;
    n %= k;
    for(int i = 0; i < n; i++){
        ans += x;
        x = x * x % m;
    }
    cout << ans << endl;
}
