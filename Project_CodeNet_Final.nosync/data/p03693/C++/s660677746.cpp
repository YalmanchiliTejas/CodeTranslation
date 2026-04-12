#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int r,g,b;

int main()
{
    cin>>r>>g>>b;
    int tmp=r*100+g*10+b;
    if(tmp%4==0)printf("YES");
    else printf("NO");
    return 0;
}
