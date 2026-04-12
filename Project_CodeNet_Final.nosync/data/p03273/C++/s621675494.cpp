#include <cstdio>
int main(void)
{
    bool rowShow[100],colShow[100];
    char bitmap[100][100];
    int row,col,i,j;
    scanf("%d%d",&row,&col);
    
    for(i=0;i<100;i++)
    {
        rowShow[i]=false;
        rowShow[i]=false;
    }


    for(i=0;i<row;i++)
    {
        getchar();
        for(j=0;j<col;j++)
        {
            scanf("%c",&bitmap[i][j]);
        }
    }

   for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {

            if(bitmap[i][j]=='#')
            {
                rowShow[i]=true;
                colShow[j]=true;
            } 
        }
    }
    for(i=0;i<row;i++)
    {
        if(rowShow[i]){
            for(j=0;j<col;j++)
            {
                if(colShow[j])
                    printf("%c",bitmap[i][j]);
            }
        printf("\n");
        }
    }

    return 0;
}
