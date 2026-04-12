#include <bits/stdc++.h>

using namespace std;
char s[10][10];
int main()
{
    int h,w,flag=1;
    cin >> h >> w;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            cin >> s[i][j];
        }
    }
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(s[i][j]=='#' && ((s[i-1][j]=='.' && s[i][j-1]=='.') || (s[i+1][j]=='#' && s[i][j+1]=='#')))
            {
                flag=0;
                break;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    if(flag)
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}
