#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int a[200002], b[200002], n;
vector<int> v;
multiset<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        auto it = s.lower_bound(x);
        if(it == s.begin()) s.insert(x);
        else
        {
            it--;
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size();
}