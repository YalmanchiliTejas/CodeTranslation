#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 10005;
char str[MAXN];
int main()
{
    int flag=0;
    scanf("%s", str);
    for(int i=0;i<strlen(str)-1;++i)
    {
        if(str[i]=='A'&&str[i+1]=='C')
        {
            flag=1;
            puts("Yes");
            break;
        }
    }
    if(!flag)
        puts("No");
    return 0;
}
