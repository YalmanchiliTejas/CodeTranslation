#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int k;
    cin >> k;

    vector<vector<int64_t>> dp(n.size(), vector<int64_t>(3, 0));
    int c0 = n.at(0) - '0';
    dp.at(0).at(0) = c0;

    int k_max = 1;
    for (int i = 1; i < n.size(); i++)
    {
        int ci = n.at(i) - '0';

        dp.at(i).at(0) = 9 + dp.at(i - 1).at(0);

        for (int j = 1; j < 3; j++)
        {
            if (k_max == j)
                dp.at(i).at(j) = 9 * (dp.at(i - 1).at(j - 1) - 1) + ci + dp.at(i - 1).at(j);
            else
                dp.at(i).at(j) = 9 * dp.at(i - 1).at(j - 1) + dp.at(i - 1).at(j);
        }

        if (ci != 0)
            k_max++;
    }

    cout << dp.at(n.size() - 1).at(k - 1) << endl;
}