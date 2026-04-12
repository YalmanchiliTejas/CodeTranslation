#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>
#include <bitset>
#include <numeric>

using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset<int> v;
    v.insert(a[0]);
    for (int i = 1; i < n; i++)
    {
        auto it = v.lower_bound(a[i]);
        if (it != v.begin())
        {
            v.erase(--it);
        }
        v.insert(a[i]);
    }

    cout << v.size() << endl;
}