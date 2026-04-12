#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, a[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    multiset<int, greater<int>> m;
    for (int i = 0; i < n; ++i)
    {
        if (m.lower_bound(a[i] - 1) == m.end())
            m.insert(a[i]);
        else
            m.erase(m.lower_bound(a[i] - 1)), m.insert(a[i]);
    }
    cout << m.size() << endl;
    return 0;
}