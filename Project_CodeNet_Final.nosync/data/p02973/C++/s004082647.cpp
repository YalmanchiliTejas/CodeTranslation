#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    multiset<int> s;
    s.insert(a[0]);
    for(int i = 1; i < n; i++)
    {
        auto itr = s.lower_bound(a[i]);
        if(itr == s.begin())
        {
            s.insert(a[i]);
        }
        else
        {
            itr--;
            s.erase(itr);
            s.insert(a[i]);
        }
    }
    cout << s.size() << endl;
}
