#include <stdio.h>

int main(void)
{
    int n;
    while(19)
    {
        scanf("%d",&n);
        if(n==0)break;
        int sum=0;
        int max=-1;
        int min=0x7fffff;
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(min>tmp)min=tmp;
            if(max<tmp)max=tmp;
            sum+=tmp;
        }
        printf("%d\n",(sum-max-min)/(n-2));
    }
    return 0;
}