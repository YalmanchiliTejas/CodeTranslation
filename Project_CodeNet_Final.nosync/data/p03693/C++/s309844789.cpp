#include <bits/stdc++.h>
using namespace std;
#define M 30005
#define N 1005

int main()
{
    int a,b,c,p;
    cin>>a>>b>>c;
    if((100*a+10*b+c)%4==0)printf("YES");
    else printf("NO");
    return 0;
}
