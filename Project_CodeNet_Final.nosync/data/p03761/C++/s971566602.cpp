#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int N;
    cin >> N;
    int a[26];
    int b[26];
    for (int j = 0; j < 26; j++)
    {
        //        b[j] = 0;
        a[j] = 50;
    }

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int ssize = s.size();
        for (int j = 0; j < 26; j++)
        {
            b[j] = 0;
            //            a[j] = 50;
        }
        for (int j = 0; j < ssize; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                char S = k + 'a';
                if (s[j] == S)
                {
                    b[k]++;
                }
            }
        }
        for (int j = 0; j < 26; j++)
        {
            //           cout << "j=" << j << ",b=" << b[j] << endl;
            a[j] = min(a[j], b[j]);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        char c;
        //      cout << a[i] << endl;
        while (a[i] > 0)
        {
            c = i + 'a';
            cout << c;
            a[i]--;
        }
    }
    cout << endl;
}