#include<stdio.h>
int main()
{
    char s[6];
    int i,open=0;
    while(scanf("%s",s)==1)
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='A'&&s[i+1]=='C')
            {
            printf("Yes\n");
            open=1;
            break;
            }
        }
        if(open==0)printf("No\n");
        open=0;
    }
    return 0;
}
