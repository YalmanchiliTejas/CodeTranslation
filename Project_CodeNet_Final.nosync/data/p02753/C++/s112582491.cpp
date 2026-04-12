#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[5];
    scanf("%s",&a);

    if(a[0]==a[1] && a[1]==a[2])
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}
