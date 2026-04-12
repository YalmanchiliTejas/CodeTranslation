#include <cstdio>
#include <string.h>
int main()
{
    char a[5];
    scanf("%s",&a);
    if(a[0]=='A'&&a[1]=='C'||a[1]=='A'&&a[2]=='C'||a[2]=='A'&&a[3]=='C'||a[3]=='A'&&a[4]=='C')
    printf("Yes");
    else
    printf("No");
} 