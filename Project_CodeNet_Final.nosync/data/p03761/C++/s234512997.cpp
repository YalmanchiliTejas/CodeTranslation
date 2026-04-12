#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<string> S;
    int use[50][26] = {0};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        S.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < S[i].size(); j++)
        {
            use[i][S[i][j] - 'a']++;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << use[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        int cnt = use[0][i];
        for (int j = 1; j < n; j++)
        {
            if (use[j][i] < cnt)
            {
                cnt = use[j][i];
            }
        }

        for (int k = 0; k < cnt; k++)
        {
            char c = 'a' + i;
            ans += c;
        }
    }

    cout << ans << endl;

    return 0;
}