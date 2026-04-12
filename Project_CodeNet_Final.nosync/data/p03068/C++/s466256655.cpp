#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, i, k;
    char s[100];
    scanf("%d",&n);
    getchar();
    scanf("%s",s);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(s[i]==s[k-1])
            printf("%c",s[i]);
        else
            printf("*");
    }
    return 0;
}
