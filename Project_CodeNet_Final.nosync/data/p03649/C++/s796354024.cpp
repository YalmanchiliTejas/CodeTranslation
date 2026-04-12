#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;
#define LL long long
#define MX 200005

int n;
LL a[55];

bool check(LL x){
    for (LL i=x; i>=max(x-n,(LL)0); --i) {
        LL sum=0;
        for (int j=1; j<=n; ++j) {
                if (i+a[j]-n<0) continue;
                sum+=max((LL)0,(i+a[j]-n)/(n+1)+1);
        }
        if (sum<=i) return true;
    }
    return false;
}
int main ()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) scanf("%lld",a+i);
    LL l=0, r=1e19+1005, mid;
    while (l<r) {
        mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",r);
    return 0;
}
