#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
const ll mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    deque<ll> a;
    rep(i, n)
    {
        int x;
        cin >> x;
        if (i % 2 == 0)
            a.push_back(x);
        else
            a.push_front(x);
    }
    if (n % 2 == 0)
    {
        rep(i, n)
        {
            int s = a.front();
            a.pop_front();
            cout << s << " ";
        }
        cout << endl;
    }
    else
    {
        rep(i, n)
        {
            int s = a.back();
            a.pop_back();
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}