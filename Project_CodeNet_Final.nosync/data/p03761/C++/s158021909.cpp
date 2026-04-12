#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    string s[n];
    rep(i, 0, n) cin >> s[i];

    int char_cnt[26];
    rep(i, 0, 26) char_cnt[i] = 1000000000;

    rep(i, 0, n)
    {
        int char_cnt_now[26] = {};
        rep(j, 0, s[i].size())
            char_cnt_now[s[i][j] - 'a']++;
        
        rep(j, 0, 26)
            char_cnt[j] = min(char_cnt[j], char_cnt_now[j]);
    }
    rep(i, 0, 26)
    rep(j, 0, char_cnt[i])
        putchar('a' + i);
    cout << endl;
    return 0;
}