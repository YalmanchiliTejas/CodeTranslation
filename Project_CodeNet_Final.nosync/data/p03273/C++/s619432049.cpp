#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
#include <ctype.h>
using namespace std;
int a,b,n;
char s[101][101];
int flag[101];
int flag2[101];
int main(void)
{
    cin >> a >> b;
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cin >> s[i][j];
            if(s[i][j] == '#')flag[i]=1;
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (s[i][j] == '#')flag2[j] = 1;
        }
    }

    for (int i = 0; i < a; i++)
    {
        if (flag[i] == 0)continue;

        for (int j = 0; j < b; j++)
        {
            if (flag2[j] == 0)continue;
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}