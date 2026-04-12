#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

bool mp; //false -> left, true -> right
string s, rightw = "yhnmjkuiolp", leftw = "bgtrfvcdewsxzaq";

bool find(string t, char c)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == c)
            return true;
    }
    return false;
}

int main()
{
    while (cin >> s)
    {
        if (s == "#")
            return 0;
        int ans = 0;
        mp = find(rightw, s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (mp == true && find(leftw, s[i]) == true)
            {
                mp = !mp;
                ans++;
            }
            if (mp == false && find(rightw, s[i]) == true)
            {
                mp = !mp;
                ans++;
            }
        }
        cout << ans << endl;
    }
}

