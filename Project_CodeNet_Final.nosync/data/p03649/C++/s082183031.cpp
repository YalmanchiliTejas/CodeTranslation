typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ll ans = 0;
    
    while(true){
        ll sum = 0;
        vector<ll> tmp(n);
        for (int i = 0; i < n; i++) {
            sum += a[i]/n;
            tmp[i]=a[i]/n;
            a[i]%=n;
        }
        ans += sum;
        if(sum==0){
            std::cout << ans << std::endl;
            return 0;
        }else{
            for (int i = 0; i < n; i++) {
                a[i] += sum-tmp[i];       
            }
        }
    }
}

