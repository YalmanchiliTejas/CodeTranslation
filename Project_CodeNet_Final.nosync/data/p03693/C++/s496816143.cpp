#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
typedef long long ll;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int sum=a*100+b*10+c;
    if(sum%4==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
