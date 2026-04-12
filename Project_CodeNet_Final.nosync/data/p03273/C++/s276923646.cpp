#include <stdio.h>
int r[1005],c[1005];
int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int i,j;
    char matrix[row][col];
    for(i=0;i<row;i++)
        scanf("%s",matrix[i]);
        if(row==1)
        {
            for(j=0;j<col;j++)
                if(matrix[0][j]=='#') printf("#");
            printf("\n");
            return 0;
        }
        if(col==1)
        {
            for(i=0;i<row;i++)
                if(matrix[i][0]=='#') printf("#\n");
            return 0;
        }
    for(j=0;j<col;j++)
    {
        for(i=1;i<row;i++)
        {
            if(matrix[i][j]=='#'||matrix[i-1][j]=='#') break;
        }
        if(i==row) c[j]=-1;
    }
    for(i=0;i<row;i++)
    {
        for(j=1;j<col;j++)
        {
            if(matrix[i][j]=='#'||matrix[i][j-1]=='#') break;
        }
        if(j==col) r[i]=-1;
    }
    for(i=0;i<row;i++)
    {
        if(r[i]!=-1)
            for(j=0;j<col;j++)
            {
                if(c[j]==0) printf("%c",matrix[i][j]);
            }
        if(r[i]!=-1) printf("\n");
    }
}
