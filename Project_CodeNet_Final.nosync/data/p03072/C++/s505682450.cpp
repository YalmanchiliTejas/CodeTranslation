#include<cstdio>
int main()
{
    int n,a[60],cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)
    {
        int flag=1;
        for(int j=0; j<i; j++)
        {
            if(a[j]>a[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
