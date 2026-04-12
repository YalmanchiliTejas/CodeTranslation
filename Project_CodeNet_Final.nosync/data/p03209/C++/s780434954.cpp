#include <iostream>
#include <vector>

using ll = long long;

std::vector<ll> bsize(1);
std::vector<ll> npatty(1);

ll calc(ll n, ll x)
{
    if (x <= n) return 0;
    if (n == 0) return 1;
    if (x == bsize[n]) return npatty[n];

    ll center = (bsize[n] + 1) / 2;
    if (x == center) return npatty[n - 1] + 1;
    if (x < center) return calc(n - 1, x - 1);
    return npatty[n - 1] + 1 + calc(n - 1, x - bsize[n - 1] - 2);
}

int main()
{
    ll n, x;
    std::cin >> n >> x;
    bsize[0] = 1;
    npatty[0] = 1;
    for (int i = 1; i <= n; i++) {
        bsize.push_back(2 * bsize[i-1] + 3);
        npatty.push_back(2 * npatty[i-1] + 1);
    }
    std::cout << calc(n, x);
    return 0;
}