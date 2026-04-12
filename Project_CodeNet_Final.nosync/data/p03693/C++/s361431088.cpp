#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 100005

int main()
{
    int a,b,c;
    char s[5];
    scanf("%s",s);
    a=s[0]-'0';
    scanf("%s",s);
    b=s[0]-'0';
    scanf("%s",s);
    c=s[0]-'0';
    int x=a*100+b*10+c;
    if (x%4==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
