#include<cstdio>
int x, y, z, ans;
int main()
{
    scanf("%d%d%d",&x, &y, &z);
    int cnt = z;
    while(cnt+y+z <= x) cnt += (y+z), ans++;
    printf("%d",ans);
    return 0;
}