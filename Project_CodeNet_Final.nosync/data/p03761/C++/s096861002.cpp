#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> table(26, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < S.size(); j++)
            table[S[j] - 'a'][i]++;
    }
    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        int maxn = *min_element(table[i].begin(), table[i].end());
        for (int j = 0; j < maxn; j++)
            ans += char(i + 'a');
    }
    cout << ans << endl;
    return 0;
}