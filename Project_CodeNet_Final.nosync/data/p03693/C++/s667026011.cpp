#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#define maxsize 100000
#define ERROR -2
#define OK 1
#define maxi 100000
using namespace std;
typedef long long ll;
int n,m,p[maxi+1];
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        if((a*100+b*10+c)%4==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

