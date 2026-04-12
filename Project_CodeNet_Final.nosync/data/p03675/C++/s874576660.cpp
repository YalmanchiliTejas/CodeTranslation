#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int a[200010];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=n;j>=1;j-=2) printf("%d ",a[j]);
    if(j==-1) j=2;
    else j=1;
    for(;j<=n;j+=2) printf("%d ",a[j]);
    return 0;
}
