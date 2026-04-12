#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> seq(n), a(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    if(n == 2){
        cout << abs(a[0]-a[1]) << endl;
        return 0;
    }else{
        ll rem = n-2;
        if(rem % 2 == 0){
            for(int i = 0; i < rem/2; i++){
                ans += 2*a[n-1-i];
            }
            for(int i = 0; i< rem/2; i++){
                ans -= 2*a[0+i];
            }
            ans += a[n/2];
            ans -= a[n/2 -1];
            cout << ans << endl;
        }else{
            for(int i = 0; i < (n+1)/2; i++){
                if(i == ((n+1)/2) -1 || i == ((n+1)/2) -2){
                    ans += a[n-1-i];
                }else{
                    ans += 2*a[n-1-i];
                }
            }
            for(int i = 0; i < (n-1)/2; i++){
                ans -= 2*a[0 + i];
            }
            ll ans2 = 0;
            for(int i = 0; i < (n-1)/2; i++){
                ans2 += 2*a[n-1-i];
            }
            for(int i = 0; i< (n+1)/2; i++){
                if(i == (n+1)/2 -1 || i == (n+1)/2 -2){
                    ans2 -= a[0+i];
                }else{
                    ans2 -= 2*a[0+i];
                }
            }
            ans = max(ans, ans2);
            cout << ans << endl;
        }
    }
    return 0;
}