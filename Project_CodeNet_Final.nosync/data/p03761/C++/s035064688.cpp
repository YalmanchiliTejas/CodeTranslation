#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string S;
    vector<int> counter(26, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> S;
        for (int j = 0; j < 26; j++)
        {
            counter[j] = min(counter[j], (int)count(S.begin(), S.end(), 'a' + j));
        }
    }

    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < counter[i]; j++)
        {
            ans.push_back('a' + i);
        }
    }
    cout << ans << endl;
}
