#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int x,y;
	char a[150][150];
	scanf("%d",&x);
	scanf("%d",&y);
	for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cin>>a[i][j];
        }
    }
	for(int i=0;i<x;i++)
    {
        int r=0;
        for(int j=0;j<y;j++)
        {
            if(a[i][j]=='#')
            {
                r++;
                break;
            }
        }
        if(r!=0)
        {
            for(int k=0;k<y;k++)
            {
            int c=0;
            for(int j=0;j<x;j++)
            {
                if(a[j][k]=='#')
                {
                    c++;
                    break;
                }
            }
            if(c!=0)
            {
                printf("%c",a[i][k]);
            }
            }
            printf("\n");
        }

    }
	return 0;
}
