#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long
const ll mod = 1000000007;

int main()
{
    ll N;
    std::cin >> N;

    std::vector<ll> A(N);
    for(ll i=0; i < N; i++) std::cin >> A[i];

    ll ans = 0;
    ll x = A[0];
    for(ll i=1; i < N; i++) {
        ans = (ans + x*A[i]) % mod;
        x = (x + A[i]) % mod;
    }
    std::cout << ans << std::endl;
}