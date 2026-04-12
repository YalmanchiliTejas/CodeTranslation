#include <stdio.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
using namespace std;
set<int> s;
map<int, int> mp;
int x[100000 + 10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    int ans = 1;
    s.insert(x[1]);
    mp[x[1]]++;
    multiset<int>::iterator it;
    for (int i = 2; i <= n; i++)
    {
        it = s.lower_bound(x[i]);
        if (it == s.begin())
        {
            s.insert(x[i]);
            mp[x[i]]++;
            ans++;
        }
        else
        {
            it--;
            mp[*it]--;
            if (mp[*it] == 0)
                s.erase(it);
            s.insert(x[i]);
            mp[x[i]]++;
        }
    }
    cout << ans << endl;
    return 0;
}