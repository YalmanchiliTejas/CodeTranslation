#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    char s[4][2]={'S','S','S','W','W','S','W','W'},a[100005],b[100005];
    int n,i,k,flag;
    scanf("%d",&n);
    scanf("%s",a);
    for(k=0;k<4;k++)
    {   flag=0;
        b[0]=s[k][0],b[1]=s[k][1];
        char temp;
        if(a[0]=='o'&&b[0]=='S')temp=b[1];
        else if(a[0]=='x'&&b[0]=='S')
        {
            if(b[1]=='S')temp='W';
            else temp='S';
        }
        else if(a[0]=='x'&&b[0]=='W')temp=b[1];
        else if(a[0]=='o'&&b[0]=='W')
        {
         if(b[1]=='W')temp='S';
         else temp='W';
        }
        for(i=1;i<n;i++)
        {
          if(a[i]=='o'&&b[i]=='S')b[i+1]=b[i-1];
        else if(a[i]=='x'&&b[i]=='S')
        {
            if(b[i-1]=='S')b[i+1]='W';
            else b[i+1]='S';
        }
        else if(a[i]=='x'&&b[i]=='W')b[i+1]=b[i-1];
        else if(a[i]=='o'&&b[i]=='W')
        {
         if(b[i-1]=='W')b[i+1]='S';
         else b[i+1]='W';
        }
        }
        if(b[n]==b[0]&&temp==b[n-1])
        {
            flag=1;
            break;
        }
    }
    b[n]='\0';
    if(flag)printf("%s\n",b);
    else printf("-1\n");
    return 0;
}
