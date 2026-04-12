#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

// modeは余り
int main()
{
    ll N;
    std::cin >> N;

    ll sum = 0;
    ll mod = 1000000007;

    std::vector<ll> A(N);
    for(ll i=0; i < N; i++) {
        ll x;
        std::cin >> x;
        A[i] = x;
    }

    int tmp = A[N-1];
    for(ll i=N-2; i >= 0; i--) {
        ll tmp2 = A[i] * tmp % mod;
        sum = (sum + tmp2) % mod;
        tmp = (tmp + A[i]) % mod;
    }

    std::cout << sum << std::endl;
}