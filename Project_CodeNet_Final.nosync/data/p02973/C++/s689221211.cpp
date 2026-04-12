// #pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const ll N = 1e5 + 5;

int main()
{
    int n, xx, c = 0;
    scanf("%d", &n);
    multiset<int> s;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &xx);
        if(s.empty())
        {
            c++;
            s.emplace(xx);
        }
        else
        {
            auto i = s.lower_bound(xx);
            if(i != s.begin()) i--;
            if(*i < xx) s.erase(i);
            else c++;
            s.emplace(xx);
        }
    }
    printf("%d\n", c);
    return 0;
}
