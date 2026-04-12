#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int n, x, ans = 0;
    multiset<int> s;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (s.empty())
            s.insert(x),
            ans++;
        else
        {
            auto it = s.lower_bound(x);
            if (it == s.end())
            {
                it--;
                s.erase(it);
                s.insert(x);
            }
            else
            {
                if (it == s.begin())
                {
                    if (*it < x)
                        s.erase(it),
                        s.insert(x);
                    else
                        s.insert(x),
                        ans++;
                }
                else
                {
                    it--;
                    s.erase(it),
                    s.insert(x);
                }
            }
        }
    }
    cout << ans;
    return 0;
}