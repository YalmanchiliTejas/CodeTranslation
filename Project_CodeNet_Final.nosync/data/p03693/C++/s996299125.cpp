#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6;
int n;

int main()
{
    int c;
    int t=100;
    int sum=0;
    for(int i=2;i>=0;i--)
    {
                 scanf("%d",&c);
                sum+=t*c;
            t/=10;
    }
    if(sum%4==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
