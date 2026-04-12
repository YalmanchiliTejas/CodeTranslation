#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int h,w;
    cin >> h >> w;
    int count = 0;
    for(int i = 0;i < h;i++)
    {
        for(int j = 0;j < w;j++)
        {
            char ch;
            cin >> ch;
            if(ch == '#')
            {
                count++;
            }
        }
    }
    if(count == (h + w - 1))
    {
        cout << "Possible\n";
    }
    else
    {
        cout << "Impossible\n";
    }
    
    return 0;
}