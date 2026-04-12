#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
using namespace std;
// std::ios::sync_with_stdio(false);
typedef long long LL;
const int N = 150000;
const int M = 12;
const int INF = 0x3f3f3f3f;
const LL MOD = 1e9+7;
const double Pi = acos(-1);
int n,m;
char s[N];
int main()
{
    while (~scanf("%s",&s))
    {
        int l = strlen(s);
        int f = 0;
        for (int i=0;i<l-1;i++)
        {
            if (s[i]=='A' && s[i+1]=='C')
            {
                f=1;
                break;
            }
        }
        if (f)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

/*


*/