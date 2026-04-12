#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[52];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    while(true){
        int l = 0;
        for(int i = 1; i < n; i++){
            if(a[i] > a[l]) l = i;
        }
        if(a[l] < n) break;
        ll c = a[l] / n;
        for(int i = 0; i < n; i++){
            if(i == l) a[i] %= n;
            else a[i] += c;
        }
        ans += c;
    }
    cout << ans << endl;
}
