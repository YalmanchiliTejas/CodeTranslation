#include<bits/stdc++.h>

using namespace std;
int main()
{
    char ss[60];
    while(~scanf("%s",ss))
    {
        if(strstr(ss,"AC"))
            printf("Yes\n");
        else printf("No\n");
    }
}
