#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        static int x;
        scanf("%d", &x);
        if (v.empty() || -v.back() >= x)
            v.push_back(-x);
        else
        {
            int i = upper_bound(v.begin(), v.end(), -x) - v.begin();
            v[i] = -x;
        }
    }

    printf("%d\n", (int)v.size());
}
