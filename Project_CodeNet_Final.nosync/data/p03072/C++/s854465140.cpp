#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll max_h = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ll h;
        cin >> h;
        if(max_h <= h){
            ans++;
        }
        max_h = max(max_h, h);
    }
    cout << ans << endl;
    return 0;
}
