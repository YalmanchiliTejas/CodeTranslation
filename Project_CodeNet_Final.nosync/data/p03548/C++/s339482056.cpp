#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int h=n-m-k-k;
    int s=0;
    if(h>0) s=h/(m+k);
    int l=0;
    if(h>=0) l=1;
    printf("%d\n",l+s);
    return 0;
}