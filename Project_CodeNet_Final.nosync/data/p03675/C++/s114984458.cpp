#include <iostream>
#include <stdio.h>
using namespace std;
int n,a[400010],l=200005,r=200005;
bool reverse;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(reverse)a[--l]=x;else a[r++]=x;
        reverse=!reverse;
    }
    if(!reverse)for(int i=l;i<r;i++)printf("%d ",a[i]);
    else for(int i=r-1;i>=l;i--)printf("%d ",a[i]);
    return 0;
}
