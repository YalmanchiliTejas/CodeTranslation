#include <iostream>
#include <string>

using namespace std;

char reverse(char c)
{
    if(c == 'S')
    {
        return 'W';
    }
    else
    {
        return 'S';
    }
}

char get(char ss, string aa)
{
    if (ss == 'o')
    {
        if (aa[1] == 'S')
        {
            return aa[0];
        }
        else
        {
            return reverse(aa[0]);
        }
    }
    if (ss == 'x')
    {
        if (aa[1] == 'S')
        {
            return reverse(aa[0]);
        }
        else
        {
            return aa[0];
        }
    }
}

int main()
{
    int N;
    string ans = "-1";
    string s, a;

    string ptr[4];
    ptr[0] = "SS";
    ptr[1] = "SW";
    ptr[2] = "WW";
    ptr[3] = "WS";

    cin >> N;
    cin >> s;


    for (int i = 0; i < 4;i++)
    {
        a = ptr[i];
        for (int j = 2; j < N;j++)
        {
            char nc = get(s[j-1], a.substr(j - 2, 2));
            a += nc;
        }
        char start = get(s[N - 1], a.substr(N - 2, 2));
        string t = a.substr(0, 2);
        reverse(t.begin(), t.end());
        char end = get(s[0], t);
        //cout << start << " " << end << endl;
        //cout << a << endl;

        if (start == a[0] && end == a[N - 1])
        {
            ans = a;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}