#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
const ll mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<int> count(26);
    string str = s[0];
    for (int i = 0; i < str.size(); i++)
    {
        count[str[i] - 'a']++;
    }
    for (int i = 1; i < n; i++)
    {
        string t = s[i];
        vector<int> cnt(26);
        for (int j = 0; j < t.size(); j++)
            cnt[t[j] - 'a']++;
        for (int j = 0; j < 26; j++)
            count[j] = min(count[j], cnt[j]);
    }
    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        if (count[i])
        {
            for (int j = 0; j < count[i]; j++)
            {
                ans += i + 'a';
            }
        }
    }
    cout << ans << endl;
    return 0;
}
