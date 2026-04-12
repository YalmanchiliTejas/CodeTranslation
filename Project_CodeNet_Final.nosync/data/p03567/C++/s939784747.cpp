#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[10];
int main()
{
    int i,j,k;
    scanf("%s",a);
    k=strlen(a);
    for(i=0;i<k-1;i++)
    {
        if(a[i]=='A'&&a[i+1]=='C')
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
