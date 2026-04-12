#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A,B,C,X,Y;
ll mini=1000000,dap=0,maxi;
int main()
{
    scanf("%lld %lld %lld %lld %lld",&A,&B,&C,&X,&Y); C*=2;
    dap = A*X+B*Y;
    mini=min(X,Y); maxi = max(X,Y);
    dap = min(dap,(C*mini)+(A*(X-mini))+(B*(Y-mini)));
    dap = min(dap,(C*maxi));
    printf("%lld",dap);
}
