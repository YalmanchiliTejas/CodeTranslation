#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n,q;
    std::cin>>n;
    std::vector<long long> a;

    for(int i = 0; i < n; i++)
    {
        int hoge;
        std::cin>>hoge;
        a.push_back(hoge);
    }

    std::cin>>q;

    for(int i = 0; i < q; i++)
    {
        int k;
        std::cin>>k;
        std::cout <<std::lower_bound(a.begin(), a.end(),k)-a.begin()<< std::endl;
    }
    return 0;
}

