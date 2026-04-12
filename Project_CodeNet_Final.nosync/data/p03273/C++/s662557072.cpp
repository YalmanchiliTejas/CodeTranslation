#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
/*int main()
{
    int h,w;
    scanf("%d %d",&h,&w);
    char a[h][w];
    for(int i=0;i<h;i++)
    {

        for(int  j=0;j<w;j++)
            scanf("%c",&a[i][j]);

    }
    int i,j;
     for( i=0;i<h;i++)
    {
        int c=0;
        for( j=0;j<w;j++)
        {
           if(a[i][j]=='#')c=1;
        }
        if(c==0)
        {
            for( j=0;j<w;j++)
            a[i][j]='0';
        }
    }
     for( j=0;i<w;j++)
    {
        int c=0;
        for(i=0;i<h;i++)
        {
           if(a[i][j]=='#')c=1;
        }
        if(c==0)
        {
           for(i=0;i<h;i++)
            a[i][j]='0';
        }
    }
    for( i=0;i<h;i++)
    {

        for( j=0;j<w;j++)
        {
           if(a[i][j]!='0')printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;

//if(a[i][j]!='0')


}*/
int i,j;
int main()
{
    int h,w;
    cin>>h>>w;
    string a[h];
    for( i=0;i<h;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<h;i++)
    {
        int c=0;
        for( j=0;j<w;j++)
        {
            if(a[i][j]=='#') c=1;
        }
        if(c==0)
        for(j=0;j<w;j++)
        {
            a[i][j]='0';
        }
        c=0;

    }
    for( j=0;j<w;j++)
    {
        int c=0;
        for(i=0;i<h;i++)
        {
           if(a[i][j]=='#')c=1;
        }
        if(c==0)
        {
           for(i=0;i<h;i++)
            a[i][j]='0';
        }
        c=0;
    }
    int m=0;
    for(  i=0;i<h;i++)
    {

        for( j=0;j<w;j++)
        {
           if(a[i][j]!='0')cout<<a[i][j];
           else m++;
        }
        if(m!=w)printf("\n");
        m=0;
    }


}
