#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[21];
    int ans = 0;
    int ma = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(ma <= a[i])
        {
            ans++;
            ma = a[i];
        }
    }
    printf("%d\n",ans);
}
