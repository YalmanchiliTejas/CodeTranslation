#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,p;
    scanf("%d %d %d",&r,&g,&b);
    p=g*10+b;
    if(p%4==0)
    printf("YES");
    else
    printf("NO");
}
