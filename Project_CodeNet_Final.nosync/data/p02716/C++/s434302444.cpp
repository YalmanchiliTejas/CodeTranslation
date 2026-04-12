#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }

    vector<vector<int64_t>> dp(n, vector<int64_t>(2, 0));
    dp.at(1).at(0) = a.at(0);
    dp.at(1).at(1) = a.at(1);
    for (int i = 2; i < n; i++)
    {
        if (i % 2 == 0)
        {
            dp.at(i).at(0) = max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));
            dp.at(i).at(1) = a.at(i) + max(dp.at(i - 2).at(0), dp.at(i - 2).at(1));
        }
        else
        {
            dp.at(i).at(0) = a.at(i - 1) + dp.at(i - 2).at(0);
            dp.at(i).at(1) = a.at(i) + dp.at(i - 1).at(0);
        }
    }
    cout << max(dp.at(n - 1).at(0), dp.at(n - 1).at(1)) << endl;
}