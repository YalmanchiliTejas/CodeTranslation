#pragma comment(linker, "/STACK:10240000")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

char str[MAXN];

int main ()
{
    scanf ("%s", &str);
    int len = strlen (str);
    bool flag = false;
    for (int i = 0; i < len; i ++)
    {
        if ((str[i] == 'A') && (i + 1 < len) && (str[i + 1] == 'C'))
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        printf ("Yes\n");
    }
    else
    {
        printf ("No\n");
    }
    return 0;
}
