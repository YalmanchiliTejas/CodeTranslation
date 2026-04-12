#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    string str;

    array<int, 26> ans;

    for (auto& x : ans)
    {
        x = 10000;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> str;

        array<int, 26> sum;

        for (auto& x : sum)
        {
            x = 0;
        }

        for (const char c : str)
        {
            sum[c - 'a']++;
        }

        for (int k = 0; k < sum.size(); ++k)
        {
            ans[k] = min(ans[k], sum[k]);
        }
    }

    for (int k = 0; k < ans.size(); ++k)
    {
        char c = 'a' + (char)k;

        for (int i = 0; i < ans[k]; ++i)
        {
            cout << c;
        }
    }
}