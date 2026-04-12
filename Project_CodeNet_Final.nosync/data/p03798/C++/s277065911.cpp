#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;
int a[100010];
char s[100010];
int n, dir[4][2] = {{0, 0}, {1, 1}, {0, 1}, {1, 0}};
int main ()
{
    scanf("%d", &n);
    scanf("%s", s);
    int f = 0;
    for(int i = 0; i < 4; i++)
    {
        a[0] = dir[i][0];
        a[1] = dir[i][1];
        for(int j = 1; j <= n; j++)
        {
            if(!a[j])
            {
                if(s[j%n] == 'o')
                    a[j+1] = a[j-1];
                else
                    a[j+1] = 1^a[j-1];
            }
            if(a[j])
            {
                if(s[j%n] == 'o')
                    a[j+1] = a[j-1]^1;
                else
                    a[j+1] = a[j-1];
            }
        }
        if(a[n] == a[0] && a[n+1] == a[1])
        {
            f = 1;
            break;
        }
    }
    if(f)
    {
        for(int i = 0; i < n; i++)
            if(a[i]) printf("W");
            else  printf("S");
        printf("\n");
    }
    else printf("-1\n");
}
