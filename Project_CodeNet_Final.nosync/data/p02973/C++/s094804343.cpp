#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() 
{
    int n; cin >> n;
    vector<int> a(n);
    for (auto &e : a)
        cin >> e;
    vector<int> current;
    for (auto i = a.rbegin(); i != a.rend(); i++)
    {
        auto v = upper_bound(current.begin(), current.end(), *i);
        if (v == current.end())
            current.push_back(*i);
        else
        {
            *v = *i;
        }
    }
    cout << current.size();
    return 0;
}