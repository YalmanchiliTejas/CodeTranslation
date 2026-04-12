#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, a;

    cin >> n;

    multiset<int> t;

    cin >> a;
    t.insert(a);

    for (int i = 1; i < n; i++)
    {
        cin >> a;

        if (*t.begin() >= a)
        {
            t.insert(a);
        }
        else
        {
            auto e = t.lower_bound(a);
            e--;
            t.erase(e);
            t.insert(a);
        }
    }

    cout << t.size() << endl;
}