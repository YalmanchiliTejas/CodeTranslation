#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int h[25];
    for(int i = 0; i < n; ++i)
        scanf("%d", &h[i]);
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int flag = 1;
        for(int j = 0; j < i; ++j)
        {
            if(h[i] < h[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
