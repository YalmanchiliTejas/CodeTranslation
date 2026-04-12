#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);

    rep(i, 0, n)
    {
        cin >> s[i];
    }
    vector<char> ans;

    //  全ての文字列に含まれるアルファベットを取り出す. (重複あり)
    int s0len = s[0].length();
    rep(i, 0, s0len)
    {
        int flg = 1;
        char c = s[0].at(i);
        int idx = 0;
        // cout << "c:" << c << endl;
        rep(j, 1, n)
        {
            rep(k, 0, s[j].length())
            {
                if (s[j].at(k) == c)
                {
                    flg++;
                    break;
                }
            }
        }
        if (flg == n)
        {
            rep(j, 1, n)
            {
                idx = 0;
                rep(k, 0, s[j].length())
                {
                    if (c == s[j].at(k))
                    {
                        idx = k;
                    }
                }
                s[j].erase(idx, 1);
            }
            ans.push_back(c);
        }
    }

    //  取り出したアルファベットを辞書順に並べる
    sort(ans.begin(), ans.end());
    rep(i, 0, ans.size())
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
