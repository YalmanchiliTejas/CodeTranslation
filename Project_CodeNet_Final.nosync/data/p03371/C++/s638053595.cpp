#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef pair<ll, ll> P;



int main(){
    ll a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
    ll ans = a*x+b*y;
        for(ll i=0; i<=max(x,y); i++){
            ans = min(ans, 2*c*i + a*max(0LL,x-i) + b*max(0LL,(y-i)));
        }
    cout << ans << endl;
}
        

            