#include <iostream>

using namespace std;
typedef long long ll;
ll mod = 1000000007,a[200010],s = 0;
int main(){
    int i,n; cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i]; (s += a[i]) %= mod;
    }
    (s *= s) %= mod;
    for(i=0;i<n;i++){
        s -= a[i]*a[i]%mod;
        if(s<0) s += mod;
    }
    (s *= (mod + 1)/2) %= mod;
    cout << s << endl;
}