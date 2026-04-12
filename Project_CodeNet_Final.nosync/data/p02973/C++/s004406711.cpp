#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n;
int cnt = 0;
multiset<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        auto it = s.lower_bound(a);
        if (it == s.begin())
        {
            s.insert(a);
        }
        else
        {
            s.erase(--it);
            s.insert(a);
        }
    }

    cout << s.size() << endl;
}