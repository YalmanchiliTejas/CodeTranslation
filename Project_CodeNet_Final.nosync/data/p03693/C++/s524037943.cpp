#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
  int a,b,c,s;
  scanf("%d%d%d",&a,&b,&c);
    s=a*100+b*10+c;
    if(s%4==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}