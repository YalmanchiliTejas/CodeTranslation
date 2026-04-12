#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n, a[200005];
int ans[200005];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int l = 0, r = n - 1;
        int cnts = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(cnts % 2 == 0)
            {
                ans[l] = a[i];
                l++;
            }
            else
            {
                ans[r] = a[i];
                r--;
            }
            cnts++;
        }
        printf("%d",ans[0]);
        for(int i = 1; i < n; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
}
