#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
int n;
multiset<int> se;
int main()
{
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    rep(i, n)
    {
        if (se.empty())
        {
            se.insert(a[i]);
        }
        else
        {
            auto it = se.upper_bound(a[i]);
            if (it != se.end())
            {
                se.erase(it);
            }
            se.insert(a[i]);
        }
    }
    cout << se.size() << endl;
}