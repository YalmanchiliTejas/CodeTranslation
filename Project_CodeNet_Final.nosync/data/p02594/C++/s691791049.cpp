#include <bits/stdc++.h>
#define ll long long
int main()
{
    ll x;
    bool flag = false;
    std::cin >> x;
    if (x >= 30) {
        flag = true;
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}