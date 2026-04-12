#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<string> bs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bs[i];
    }
    vector<vector<int>> chrs(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bs[i].size(); j++)
        {
            int k = int(bs[i][j]);
            chrs[i][k - 97]++;
        }
    }
    vector<char> l;
    for (int i = 0; i < 26; i++)
    {
        int k = 50 * 100;
        for (int j = 0; j < n; j++)
        {
            k = min(k, chrs[j][i]);
        }
        for (int j = 0; j < k; j++)
        {
            l.emplace_back(char(97 + i));
        }
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < l.size(); i++)
    {
        cout << l[i];
    }
    cout << endl;
}