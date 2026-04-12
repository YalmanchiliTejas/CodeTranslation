#include<stdio.h>

//#define rep(i, rep_m) for(int i = 0; i < (int)(rep_m); i++)

int main()
{
    int tmp,color[100001];
    int n,m=1;
    int i,j;
    
    scanf("%d",&n);
    
    scanf("%d",&tmp);
    color[0] = tmp;
    
    for(i=1;i<n;i++)
    {
        scanf("%d",&tmp);
        
        if(tmp <= color[m-1])
        {
            color[m] = tmp;
            m++;
        }
        else
        {
            for(j=0;j<m;j++)
            {
                if(tmp > color[j])
                {
                    color[j] = tmp;
                    break;
                }
            }
        }
    }
    
    printf("%d\n",m);
    
    return 0;
}
