#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N(2e5 + 9);

int T, n, m, ans;

int main()
{
    cin >> n;
    multiset<int>dp;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        auto pos = dp.lower_bound(x);
        if (pos == dp.begin()) dp.insert(x);
        else
        {
            pos--;
            dp.erase(pos);
            dp.insert(x);
        }
    }
    cout << dp.size() << endl;
}
