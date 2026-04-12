#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;

    std::cin >> n;

    std::vector<std::vector<int>> vec;

    int ca = -1;

    rep(i, n)
    {
        int a;
        std::cin >> a;
        if (a > ca)
        {
            vec.push_back(std::vector<int>());
            vec.rbegin()->push_back(a);
        }
        else
        {
            vec.rbegin()->push_back(a);
        }
        ca = a;
    }

    //std::cerr << "DEBUG" << std::endl;
    /*for (auto &v : vec)
    {
        for (int x : v)
            std::cerr << x << ' ';
        std::cerr << std::endl;
    }*/

    std::multiset<int> set;

    for (auto &v : vec)
    {
        for (int x : v)
        {
            if (set.empty() || *(set.begin()) >= x)
            {
                set.insert(x);
                continue;
            }
            auto it = set.lower_bound(x);
            --it;
            set.erase(it);
            set.insert(x);
        }
    }

    std::cout << set.size() << std::endl;

    return 0;
}