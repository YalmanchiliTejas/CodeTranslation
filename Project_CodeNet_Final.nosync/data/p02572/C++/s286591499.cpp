#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
        ll n,i,s=0,ans=0;
        cin >> n;
        vector<ll> a(n);
        vector<ll> p(n-1);
        for(i=0;i<n;++i){
                cin >> a.at(i);
                s += a.at(i);
        }
        s %= MOD;
        for(i=0;i<n-1;++i){
                s -= a.at(i);
                if(s<0) s += MOD;
                ans += s*a.at(i);
                ans %= MOD;
        }
        cout << ans << endl;
        return 0;
}