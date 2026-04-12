#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    string s[n];
    rep(i, 0, n)
    {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }

    map<char, int> char_cnt;
    rep(i, 0, n)
    {
        map<char, int> now_char_cnt;
        int j = 0;
        while (j < s[i].size())
        {
            char now = s[i][j];
            int cnt = 0;
            for (;j < s[i].size() and s[i][j] == now; j++)
                cnt++;
            now_char_cnt[now] = cnt;
        }

        // merge
        if (i == 0)
            char_cnt = now_char_cnt;
        else
        {
            for (auto c_cn: char_cnt)
                char_cnt[c_cn.first] = min(c_cn.second, now_char_cnt[c_cn.first]);
        }
    }

    vector<char> ans;
    for (auto c_cn: char_cnt)
    {
        char c = c_cn.first;
        int cnt = c_cn.second;
        rep(i, 0, cnt)
            ans.push_back(c);
    }
    sort(ans.begin(), ans.end());
    rep(i, 0, ans.size())
        cout << ans[i];
    cout << endl;
    return 0;
}