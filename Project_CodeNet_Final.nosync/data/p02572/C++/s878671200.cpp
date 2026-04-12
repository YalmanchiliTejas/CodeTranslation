#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int main() {
        
        int n;
        cin  >> n;
        ll ans = 0,  b = 0;
        vector<int > a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
            
        for(int i = 0; i < n; ++i)
        {
            ans += (a[i]*b)%mod;
            b = (b+a[i])%mod;
        }
        cout << ans%mod;
}
