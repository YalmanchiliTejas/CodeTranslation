#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI acos(-1.0)
#define N 200005
#define eps 1e-8
int  n,i,a[N];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n%2==0){
    for(i=n;i>0;i-=2)
        printf("%d ",a[i]);
    for(i=1;i<=n;i+=2)
        printf("%d ",a[i]);
    }
    else{
        for(i=n;i>0;i-=2)
        printf("%d ",a[i]);
    for(i=2;i<=n;i+=2)
        printf("%d ",a[i]);
    }
    return 0;
}
