#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[10];

int main()
{
    scanf("%s",s);
    bool a=0,b=0;
    for (int i=0;i<3;i++) if (s[i]=='A') a=1;
    else b=1;
    if (a&b) printf("Yes\n");
    else printf("No\n");

    return 0;
}
