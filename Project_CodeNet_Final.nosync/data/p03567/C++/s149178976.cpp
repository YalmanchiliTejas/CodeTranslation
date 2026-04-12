#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[11];
int ans,lena;
int main()
{
    scanf("%s",a);
    lena=strlen(a);
    for(int i=0;i<=lena;i++)
    {
        if(a[i]=='A'&&a[i+1]=='C')
        {
            ans++;
            break;
        }
    }
    if(ans==1)
    {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 0;
}