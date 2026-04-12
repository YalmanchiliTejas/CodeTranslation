typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}

int main() {
    ll n;
    std::cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    ll now = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if( h[i] >= now ){
            cnt++;
            now = h[i];
        }
    }
    std::cout << cnt << std::endl;
}
