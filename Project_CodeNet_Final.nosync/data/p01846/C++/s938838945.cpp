#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "#")
            break;
        int a, b, c, d;
        int i = 0, j = 0;
        cin >> a >> b >> c >> d;
        char t[20][20];
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                t[i][j] = ' ';
            }
        }
        for (char c : s)
        {
            if (c == '/')
            {
                i++;
                j = 0;
            }
            else if (c == 'b')
            {
                t[i][j] = 'b';
                j++;
            }
            else
            {
                for (int k = 0; k < c - '0'; k++)
                {
                    t[i][j] = '.';
                    j++;
                }
            }
        }
        string ans;
        int cnt = 0;
        swap(t[a - 1][b - 1], t[c - 1][d - 1]);
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                if (t[i][j] == '.')
                {
                    cnt++;
                }
                else if (t[i][j] == 'b')
                {
                    if (cnt != 0)
                    {
                        ans += to_string(cnt);
                    }
                    ans.push_back('b');
                    cnt = 0;
                }
            }
            if(cnt!=0){
                ans+=to_string(cnt);
                cnt=0;
            }
            if (t[i + 1][0] == ' ')
            {
                break;
            }
            else
            {
                ans.push_back('/');
            }
        }
        cout << ans << endl;
    }
}
