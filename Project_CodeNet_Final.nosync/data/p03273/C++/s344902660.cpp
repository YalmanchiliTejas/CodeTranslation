#include<stdio.h>

int main()
{
    char grid[150][150];
    int myH[150], myW[150];
    int i, j, ind, h, w;
    scanf("%d %d", &h, &w);
    for(i=0;i<h;i++)
        scanf("%s", grid[i]);
    for(i=0;i<h;i++)
    {   
        ind=0;
        for(j=0;j<w;j++)
        {
            if(grid[i][j]=='#')    
                break;
            else if(j==w-1)
                ind=1;
        }
        if(ind==1)
            myH[i]=1;
    }
    for(j=0;j<w;j++)
    {   
        ind=0;
        for(i=0;i<h;i++)
        {
            if(grid[i][j]=='#')    
                break;
            else if(i==h-1)
                ind=1;
        }
        if(ind==1)
            myW[j]=1;
    }
    for(i=0;i<h;i++)
    {
        if(myH[i]==1) 
            continue;
        for(j=0;j<w;j++)
        {
            if(myW[j]!=1)    
                printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}