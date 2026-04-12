#include<bits/stdc++.h>
using ll = long long;

int main()
{
    int n,k;
    std::cin >> n >> k;
    ll cnt = 0;
    for(int b = k + 1; b <= n; b++){
        int cur = 0;
        cur += (n / b) * (b - k); 
        int now = (n / b) * b;
        int lim = n - now;
        cur += std::max(lim - (k - 1),0);
        cnt += cur;
    }
    if(k == 0)cnt = (ll)n * n;
    std::cout << cnt << std::endl;

}
