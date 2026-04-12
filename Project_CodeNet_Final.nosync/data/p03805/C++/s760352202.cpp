#include <stdio.h>
#include <string.h>

int n,m,flag[8][28],ans=0;

int find(int p,int aleady[],int count)
{
	int i,num=0;
	if(count ==n)return 1;
    else {
    	aleady[p] = 1;
	    for (i = 0; i < n; ++i)
	    {
    		if(flag[p][i] == 1 && aleady[i] == 0)
    		{
    		    num = num + find(i,aleady,count+1);
    		}

	    }
	    aleady[p]=0;
        return num;
    }
}

int main()
{
	int a,b,i,j,ans,aleady[8],count;

	scanf("%d%d",&n,&m);
    ans = 0;
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < m; ++j)
	    {
	    	flag[i][j] = 0;
	    }
	    aleady[i] = 0;
    }
    for (i = 0; i < m; ++i)
    {
    	scanf("%d%d",&a,&b);
        flag[a-1][b-1] = 1;
        flag[b-1][a-1] = 1;
    }



    aleady[0] = 1 ;

    printf("%d\n", find(0,aleady,1));
	return 0;
}