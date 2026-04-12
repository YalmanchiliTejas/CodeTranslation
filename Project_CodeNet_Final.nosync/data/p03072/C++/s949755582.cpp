#include<cstdio>
#include<iostream>
#include<algorithm>
#define SIZE 10010

using namespace std;

int main()
{
    int n,i,a,total=0;
    int tmp=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a>=tmp)
        {
            total++;
            tmp=a;
        }
    }
    printf("%d\n",total);
    return 0;
}
