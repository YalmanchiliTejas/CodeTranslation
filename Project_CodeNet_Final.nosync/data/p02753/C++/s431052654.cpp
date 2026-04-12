#include<stdio.h>
#include<string.h>
using namespace std;
char s[5];
int main()
{
    scanf("%s",s);
    int cnt=0;
    for(int i=0;i<3;i++)
        if(s[i]=='A') cnt++;
    if(cnt==0||cnt==3) printf("No\n");
    else printf("Yes\n");
    return 0;
}
