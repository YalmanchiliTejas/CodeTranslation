#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005];
int main()
{

    int n;
    char s[5];
    scanf("%s",s+1);
    int a=0,b=0;
    for(int i=1;i<=3;i++)
    {
        if(s[i]=='A')a++;
        else b++;
    }
    if(a&&b)printf("Yes\n");
    else printf("No\n");
}
