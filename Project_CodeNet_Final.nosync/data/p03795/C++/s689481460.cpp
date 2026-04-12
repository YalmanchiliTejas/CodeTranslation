#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",800*n-200*(n/15));
    return 0;
}