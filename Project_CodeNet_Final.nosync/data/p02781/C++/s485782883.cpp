#include <bits/stdc++.h>

using namespace std;

int k;
string s;
string t;

int Rec(int i = 0, int Last = -1)
{
    if(i == k)  return t <= s;

    int Res = 0;

    for(int j = Last + 1; j < s.size(); j++)
    {
        if(t[j] == '0')
        {
            for(int r = 1; r < 10; r++)
            {
                t[j] = r + '0';
                Res += Rec(i + 1, j);
                t[j] = '0';
            }
        }
    }

    return Res;
}

int main()
{
    cin >> s >> k;

    t = string(s.size(), '0');

    cout << Rec() << endl;
}
